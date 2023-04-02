#include "robot.h"

int main()
{
    char choice = 'n';
    while (true) {
        cout << "Enter behavior [w/r]\n"; // Enter w/r to start with walkBehavior/runBehavior
        cin >> choice;
        if ( choice == 'q' ) { // q to quit
            printf("quit\n");
            break;
        }
        behavior* test_behavior; // base class pointer 
        switch (choice) {
            case 'w':
                test_behavior = new walkBehavior("walker"); // spawn a walk behavior
                break;

            case 'r':
                test_behavior = new runBehavior("runner"); // spawn a run behavior
                break;

            default:
                continue;
        }
        test_behavior->action(); // override 'automatically'
        delete test_behavior;
    }
    
    return 0;
}