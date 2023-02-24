#include <iostream>
using namespace std;

string FileName(string location[],int fileNumber)
{
	string fileName;
	int count=0;
	int positionOfSlash;
	int positionOfDot ;
	bool slashFound = false;
	bool dotFound = false;
	int lengthOfLocation = location->length();
	for(int i=lengthOfLocation-1;i>=0;i--)
	{
		if(location[fileNumber][i]=='/')
		{
			slashFound = true;
			positionOfSlash = i;
		}
		else if(location[fileNumber][i]=='.')
		{
			dotFound = true ;
			positionOfDot =i;
		}
		if(dotFound == true && slashFound == true)
		{
			break;
		}
	}
	// for (int i=0;i<lengthOfLocation;i++)
	// {
	// 	if( location[fileNumber][i]== '/' )
	// 	{
	// 		count++;
	// 	}
	// }
	// for (int i=0;i<lengthOfLocation;i++)
	// {
	// 	if(location[fileNumber][i]== '/')
	// 	{
	// 		positionOfSlash ++;
	// 		if(positionOfSlash == count)
	// 		{
	// 			positionOfSlash = i;
	// 		}
	// 	}
	// }
	// for (int i=0;i<lengthOfLocation;i++)
	// {
	// 	if(location[fileNumber][i]== '.')
	// 	{
	// 		positionOfDot = i;
	// 	}
	// }
	for(int i=positionOfSlash+1;i<positionOfDot;i++)
	{
		char temp =location[fileNumber][i];
		fileName +=	temp;
	}
	return fileName;
}

void Display(string location[], int file)
{
	for (int i=0;i<file;i++)
	{
		string fileName = FileName(location,i);
		cout<<"FILE NAME : "<<fileName<<endl;
		cout<<location[i]<<endl;
	}
}

int Random(int lowerLimit, int upperLimit)
{
	int random = lowerLimit + (rand()%(upperLimit - lowerLimit + 1));
	return random;
}



string RandomName()
{
	int length = Random(5,10);
	string name = "";
	for(int i=0; i<length; i++)
	{
		char min = 'a';
		char max = 'z';
		char letter = min +(rand()%(max-min+1));
		name += letter;
	}
	return name;
}

int main() 
{
	srand(time(0));
	int file = Random(3,5);
	string location[file];
	for(int i=0;i<file;i++)
	{
		int locationCount = Random(3,5);
		for (int j =0;j<locationCount;j++)
		{
			string name = RandomName();
			location[i] += name;
			if(j!=locationCount-1)
				location[i] += '/';
		}
		location[i]+= ".abel";
	}
	Display(location,file);
}