#!/usr/bin/python
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
from ctypes import cdll
from argparse import ArgumentParser
from ctypes import cdll
import ctypes
import os
import traceback
import sys
import time



"""

This is an Example of using the Python connectors. The example will accept user input
create a table writing arbitrary information to it via the BatchWriter and scanner will put the written data      
     
             
"""

parser = ArgumentParser(description="This is an Apache Accummulo Python connector")

parser.add_argument("-i", "--instance", dest="instance",
                    help="Apache Accumulo Instance Name", required=True)
parser.add_argument("-z", "--zookeepers", dest="zookeepers",
                    help="Comma Separated Zookeeper List", required=True)
parser.add_argument("-u", "--username", dest="username",
                    help="User to access Apache Accumulo", required=True)
parser.add_argument("-p", "--password", dest="password",
                    help="Password to access Apache Accumulo. May also be supplied at the command line")
parser.add_argument("-t", "--table", dest="table",
                    help="Table to create/update")
args = parser.parse_args()

password = args.password
table = args.table

if not password:
    print("Please enter your password")
    password = input()
    
if not table:
    table = "blahblahd"

import pysharkbite

conf = pysharkbite.Configuration()

conf.set ("FILE_SYSTEM_ROOT", "/accumulo");

zk = pysharkbite.ZookeeperInstance(args.instance, args.zookeepers, 1000, conf)

user = pysharkbite.AuthInfo(args.username, password, zk.getInstanceId()) 

try:
    connector = pysharkbite.AccumuloConnector(user, zk)


    tableOperations = connector.tableOps(table)

    if not tableOperations.exists(False):
        print ("Creating table " + table)
        tableOperations.create(False)  
    else:
        print (table + " already exists, so not creating it")  
    
    
    auths = pysharkbite.Authorizations()
    
    """ Add authorizations """ 
    """ mutation.put("cf","cq","cv",1569786960) """
    
    writer = tableOperations.createWriter(auths, 10)
    
    mutation = pysharkbite.Mutation("row2");    
    
    mutation.put("cf","cq","",1569786960, "value")
    mutation.put("cf2","cq2","",1569786960, "value2")
    """ no value """
    mutation.put("cf3","cq3","",1569786960, "") 
    
    writer.addMutation( mutation )
    
    writer.close()
    
    time.sleep(2)
    
    """ auths.addAuthorization("cv") """
    
    scanner = tableOperations.createScanner(auths, 2)
    
    startKey = pysharkbite.Key()
    
    endKey = pysharkbite.Key()
    
    startKey.setRow("row")
    
    endKey.setRow("row3")
    
    range = pysharkbite.Range(startKey,True,endKey,False)
    
    scanner.addRange( range )
    
    resultset = scanner.getResultSet()
    
    for keyvalue in resultset:
        key = keyvalue.getKey()
        value = keyvalue.getValue()
        
    
    """ delete your table if user did not create temp """
    if not args.table:
        tableOperations.remove()
    
except RuntimeError as e:
     traceback.print_exc()
     print("Oops, error caused: " + str(e))
