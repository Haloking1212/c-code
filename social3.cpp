//Vincent Perez
//nov 2019
//social network program


#include <iostream>
#include <cctype>
using namespace std;

class Profile
{
public:
	Profile(string usrn, string dspn);
	Profile();
	string getUsername();
	string getFullName();
	void setDisplayName(string dspn);
private:
	string username;
	string displayname;
};

class Network {
private:
    static const int MAX_USERS = 20; 
    int numUsers;                    
    Profile profiles[MAX_USERS];     
    bool following[MAX_USERS][MAX_USERS];    // new 
    int findID (string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2); // new
    void printDot();                         // new
};


////////// ----PROFILE FUNCTIONS

//returns the username of profile
string Profile::getUsername()
{
	return username;
}

//returns the full name with the username in created profile
string Profile::getFullName()
{
	string fullname;
	fullname = displayname + " (@" + username + ")";
	return fullname;
}

//if wanted to change displayname, function changes diplayname
void Profile::setDisplayName(string dspn)
{
	displayname = dspn;
}

//sets value to user input
Profile::Profile(string usrn, string dspn)
{
	username = usrn;
	displayname = dspn;
}

//constructor for profiles
Profile::Profile()
{
	username = "";
	displayname = "";
}

//////// ----------NETWORK FUNCTIONS

//constructor for users
Network::Network()
{
	numUsers = 0;
	for (int i = 0; i<MAX_USERS; i++)
		{
			for (int j = 0; j<MAX_USERS; j++)
				{
					following[i][j] = false;
				}
		}
}

int Network::findID(string usrn)
{
int rtrn = 0;
	for (int i = 0; i<MAX_USERS; i++)
		{
			if (profiles[i].getUsername() == usrn)
				{
					rtrn = i;
                    return rtrn;
				}
		}
rtrn = -1;
return rtrn;
}

bool Network::addUser(string usrn, string dspn)
{
if ((numUsers < MAX_USERS == true) and (findID(usrn) == -1) and (usrn != ""))
	{
		for (int i = 0; i<usrn.length(); i++)
				{
					if (!isalnum(usrn[i]))
						{
							return false;
						}
				}
		profiles[numUsers] = {usrn,dspn};
		numUsers = numUsers + 1;
		return true;
	}
return false;
}

//makes two users follow each other
bool Network::follow(string usrn1, string usrn2)
{
int usr1 = findID(usrn1);
int usr2 = findID(usrn2);
if (usr1 != -1 and usr2 != -1)
	{
		following[usr1][usr2] = true;
        return true;
	}
else
	{
		return false;
	}
return false;
}

void Network::printDot()
{
cout<<"digraph {"<<endl;
for (int i = 0; i < numUsers; i++)
{
    cout<<'"'<<"@"<<profiles[i].getUsername()<<'"'<<endl;
}

for (int i = 0; i<numUsers; i++)
	{
		for (int j = 0; j<numUsers;j++)
			{
                //cout<<i<<" "<<j<<endl;
				if (following[i][j] == true)
					{
						cout<<'"'<<"@"<<profiles[i].getUsername()<<'"'<<" -> "<<'"'<<"@"<<profiles[j].getUsername()<<'"'<<endl;
					}
			}
	}
cout<<"}"<<endl;
}


//checks if two users are following each other


int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    //make @mario2 follow @luigi
    nw.follow("mario2", "luigi");
    nw.printDot();

}
