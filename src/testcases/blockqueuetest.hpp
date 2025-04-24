
#include "blockqueue.hpp"
#include <iostream>;
using std::cout;


//tests whether the blockqueue's bag system goes through all possible tetrominos before repeating
class BlockQueueTest {
public:
	BlockQueueTest();
	void run();

private:
	BlockQueue queue;

};

BlockQueueTest::BlockQueueTest() {

}

void BlockQueueTest::run() {
	bool hasFailed = false;
	bool arr[7] = { false};

	//pull 7 different blocks from the queue, mark off which ids were drawn in an array
	//fails if the same block is drawn twice within 7 pulls
	for (int i = 0; i < 7; i++) {
		int id = queue.getBlock()->getId();
		if (arr[id]) {
			cout << "Test failed: Duplicate shapes within bag\n";
			hasFailed = true;
			return;
		}
		arr[id] = false;
	}

	if (!hasFailed) {
		cout << "Block Queue Test Passed!\n";
	}

}