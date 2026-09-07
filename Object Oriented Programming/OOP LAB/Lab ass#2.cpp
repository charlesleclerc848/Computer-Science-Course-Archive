#include<iostream>
using namespace std;
//template<typename T>
		template<typename T1,typename T2,typename T3>
class UserProfile{
	private:
	T1 userID;
	
	T2 userLevel;
		
	T3 increment;
	
	public:
		void setProfile(T1 id, T2 level){
			userID=id;
			userLevel=level;
		}
			void upgradeLevel(T3 inc){
				increment =inc;
				
			}
	void displayProfile(){
		cout<<"User ID : "<<userID<<" , Current Level : "<<userLevel<<endl;
		cout<<"Before Upgrade  User Level : "<<userLevel<<endl;
		cout<<"After Upgrade  User Level : "<<userLevel+increment<<endl;
        cout<<"User ID : "<<userID<<" , Current Level : "<<userLevel+increment<<endl;

	}
	
	
	
};

int main() { 
UserProfile<int, int, int> user1;
 user1.setProfile(1, 10);
  user1.upgradeLevel(5); 
  user1.displayProfile(); 
  UserProfile<string, double, double> user2; 
  user2.setProfile("User2", 10.5); 
  user2.upgradeLevel(5.5); 
  user2.displayProfile();
   return 0;
    }