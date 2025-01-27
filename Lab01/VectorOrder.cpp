#include <iostream>
#include <vector>
using namespace std;


bool inOrder(const vector<int> &nums);

int main() {

	vector<int> nums1(5);
	nums1.at(0) = 5;
	nums1.at(1) = 6;
	nums1.at(2) = 7;
	nums1.at(3) = 8;
	nums1.at(4) = 3;


	if (inOrder(nums1)) {
		cout << "First vector is in order" << endl;
	}
	else {
		cout << "First vector is not in order" << endl;
	}

	vector<int> nums2(5);
   
   // Fill second vector with 5 integers entered by the user
    for (unsigned int i = 0; i < nums2.size(); ++i){
        cin >> nums2[i];
    }

   // Output whether second vector is in order or not in order
    if (inOrder(nums2)) {
		cout << "Second vector is in order" << endl;
	}
	else {
		cout << "Second vector is not in order" << endl;
	}

	return 0;
}

// Define your inOrder function here
bool inOrder(const vector<int> &nums){

    for(unsigned int i = 1; i < nums.size(); ++i){
        if ((nums[i-1]) > nums[i]){
            return false;
        } 
    }
    return true;
}