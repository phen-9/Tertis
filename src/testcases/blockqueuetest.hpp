
#include "blockqueue.hpp"


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
	bool arr[7] = { false, false, false, false, false, false, false };
	for (int i = 0; i < 7; i++) {
		int id = queue.getBlock()->getId();
		if (arr[id]) {
			cout << "Test failed: Duplicate shapes within bag\n";
		}
		arr[id] = false;

	}


}