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
#ifndef INCLUDE_DATA_CONSTRUCTS_RFILE_META_BLOCK_H_
#define INCLUDE_DATA_CONSTRUCTS_RFILE_META_BLOCK_H_

#include "BaseMetaBlock.h"
#include "IndexBlock.h"
#include "BlockLookup.h"
#include <memory>
#include "../../Key.h"
#include "data/streaming/Streams.h"

namespace cclient {
namespace data {

class Block: public BaseMetaBlock, public std::enable_shared_from_this<Block> {
protected:
	std::shared_ptr<Block> parent;
	std::shared_ptr<IndexBlock> indexBlock;
	uint32_t currentPosition;
	BlockLookup *blockStore;

public:

	Block(BlockLookup *blockStore, std::shared_ptr<Block> parent,
			std::shared_ptr<IndexBlock> block) :
			blockStore(blockStore), parent(parent), indexBlock(block), currentPosition(
					0) {

	}

	Block(BlockLookup *blockStore, std::shared_ptr<IndexBlock> block) :
			Block(blockStore, NULL, block) {

	}

	Block(std::shared_ptr<Block> blockStore, std::shared_ptr<IndexBlock> block) :
			Block(blockStore->blockStore, blockStore, block) {

	}

	~Block() {
	}

	uint32_t getCurrentPosition() {
		return currentPosition;
	}

	std::shared_ptr<IndexBlock> getIndexBlock() {
		return indexBlock;
	}

	std::shared_ptr<data::streams::StreamInterface> getBlock() {
		return indexBlock->getIndex();
	}

	uint32_t getOffset() {
		return indexBlock->getOffset();
	}

	bool hasNextKey() {
		return indexBlock->hasNextKey();
	}

	std::shared_ptr<IndexBlock> getIndexBlock(std::shared_ptr<IndexEntry> ie) {
		return blockStore->getIndexBlock(ie);
	}

	std::shared_ptr<Block> lookup(std::shared_ptr<Key> key) {
		int64_t posCheck = indexBlock->getKeyIndex()->binary_search(key);
		if (posCheck < 0) {
			posCheck = (posCheck * -1) - 1;
		}
		uint64_t pos = posCheck;
		if (pos == indexBlock->getIndex()->size()) {
			if (parent != NULL) {
				throw std::runtime_error("Illegal state");
			}
			currentPosition = pos;
			return shared_from_this();
		}

		currentPosition = pos;
		if (indexBlock->getLevel() == 0) {
			return shared_from_this();
		}

		std::shared_ptr<IndexEntry> ie = indexBlock->getIndex()->get(pos);
		std::shared_ptr<Block> newChild = std::make_shared<Block>(
				shared_from_this(), getIndexBlock(ie));

		std::shared_ptr<Block> returnBlock = newChild->lookup(key);

		return returnBlock;

	}

	std::shared_ptr<Block> getLast() {
		currentPosition = indexBlock->getIndex()->size() - 1;
		if (indexBlock->getLevel() == 0) {
			return NULL;
		}

		std::shared_ptr<IndexEntry> ie = indexBlock->getIndex()->get(
				currentPosition);
		std::shared_ptr<Block> newChild = std::make_shared<Block>(
				shared_from_this(), getIndexBlock(ie));
		std::shared_ptr<Block> returnBlock = newChild->getLast();
		if (returnBlock != NULL) {
			newChild = nullptr;
		} else
			returnBlock = newChild;

		return returnBlock;

	}

	std::shared_ptr<BaseMetaBlock> getPrevious() {
		if (currentPosition == 0) {
			return parent->getPrevious();
		}

		currentPosition--;

		std::shared_ptr<IndexEntry> ie = indexBlock->getIndex()->get(
				currentPosition);
		std::shared_ptr<Block> newChild = std::make_shared<Block>(
				shared_from_this(), getIndexBlock(ie));
		std::shared_ptr<Block> returnBlock = newChild->getLast();
		if (returnBlock != NULL) {
			newChild = nullptr;
		} else
			returnBlock = newChild;
		return returnBlock;

	}

	std::shared_ptr<BaseMetaBlock> getPreviousBlock() {
		return parent->getPrevious();
	}

};
}
}
#endif /* INCLUDE_DATA_CONSTRUCTS_RFILE_META_BLOCK_H_ */
