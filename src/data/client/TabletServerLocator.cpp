/*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "../../../include/data/client/TabletServerLocator.h"
#include "../../../include/data/client/TabletLocationObtainer.h"
#include "../../../include/data/client/TabletLocation.h"

namespace cclient
{
namespace impl
{

TabletServerLocator::TabletServerLocator (std::string tableId,
                TabletLocator *parent,
                TabletLocationObtainer *lc,
                cclient::data::Instance *inst) :
	tableId (tableId), parent (parent), locator (lc), instance (inst)
{
	std::cout << "table id for locator is " << tableId << std::endl;
	lastTabletRow = tableId;
	lastTabletRow.append ("<");

}

TabletServerLocator::~TabletServerLocator ()
{
  invalidateCache();
}

} /* namespace data */
} /* namespace cclient */
