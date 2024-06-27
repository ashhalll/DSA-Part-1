#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> myQueue;

    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    cout << myQueue.front() << endl;
    cout << myQueue.back() << endl;
    cout << myQueue.size() << endl;

    myQueue.pop();

    cout << myQueue.size() << endl;
    cout<<myQueue.front();
    if (myQueue.empty()) {
        cout << "The queue is empty." << endl;
    } else {
        cout << "The queue is not empty." << endl;
    }
}
