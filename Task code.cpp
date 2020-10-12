#include<bits/stdc++.h>
using namespace std;

class teachersTool{

	vector<pair<string,int> > entries;
	int lastAddedLevel;

public:	
	
	//Constructor for initializing first level to 0
	teachersTool()
	{
		lastAddedLevel = 0;
		entries.clear();
	}
	
	//Function to add new entry		
	void addEntry()
	{
		string name;
		cout<<"Enter new entry:\n";
		cin.ignore();
		getline(cin, name);		
		
		for(int i=0;i<lastAddedLevel;i++)
			name = "\t" + name;
			
		entries.push_back(make_pair(name,lastAddedLevel));
		cout<<"Entry added successfully.\n";
		printEntries();
	}
	
	//Function to make particular entry indent
	void indentEntry()
	{
		if(!entries.size())
		{
			cout<<"List is empty. First add entries in list.\n\n";
			return;
		}
		string name;
		cout<<"Enter entry you wish to indent:\n";
		cin.ignore();
		getline(cin, name);					
					
		int i,fnd=0,n=entries.size();
		
		//finding index of given entry
		for(i = 0; i < n; i++)
		{
			string s = entries[i].first.substr(entries[i].second,entries[i].first.size()-entries[i].second);
			if(s == name)
			{
				fnd = 1;
				break;
			}
		}
		
		//If not found in list,
		if(fnd == 0)
		{
			cout<<"No entries with given name exists\n";
			return;
		}
		
		/* If entry is first element of list or element above 
		given entry is at lesser level than given entry's 
		level, we cannot indent	given entry, */
		if(i==0 || entries[i].second>entries[i-1].second)
		{
			cout<<"Cannot indent entry\n";
			return;
		}
		
		
		int currLevel = entries[i].second;
		
		//Adding tab to given entry
		entries[i].second++;
		entries[i].first = "\t"+entries[i].first;
		i++;
		
		//Adding tab to all its child entries if they exists,
		while(i<n && entries[i].second>currLevel)
		{
			entries[i].second++;
			entries[i].first = "\t"+entries[i].first;
			
			i++;
		}
		
		lastAddedLevel = entries[n-1].second;
		
		cout<<"Entry indented successfully.\n";
		printEntries();
	}
	
	//Function to make particular entry outdent
	void outdentEntry()
	{
		if(!entries.size())
		{
			cout<<"List is empty. First add entries in list.\n\n";
			return;
		}
		
		string name;
		cout<<"Enter entry you wish to outdent:\n";
		cin.ignore();
		getline(cin, name);
		
		int i,fnd=0,n=entries.size();
		
		//finding index of given entry
		for(i = 0; i < n; i++)
		{
			string s = entries[i].first.substr(entries[i].second,entries[i].first.size()-entries[i].second);
			if(s == name)
			{
				fnd = 1;
				break;
			}
		}
		
		//If not found in list,
		if(fnd == 0)
		{
			cout<<"No entries with given name exists\n";
			return;
		}
		
		//If given entry is already at zero level, we cannot outdent,
		if(entries[i].second == 0)
		{
			cout<<"Cannot outdent entry\n";
			return;
		}	
		
		int currLevel = entries[i].second;
		
		//Removing tab from given entry
		entries[i].second--;
		entries[i].first = entries[i].first.substr(1,entries[i].first.size()-1);
		i++;
		
		//Removing tab from all its child entries
		while(i<n && entries[i].second>currLevel)
		{
			entries[i].second--;
			entries[i].first = entries[i].first.substr(1,entries[i].first.size()-1);
		
			i++;
		}
		
		lastAddedLevel = entries[n-1].second;
		
		cout<<"Entry outdented successfully.\n";
		printEntries();
	}
	
	//Function to delete entry
	void deleteEntry()
	{
		if(!entries.size())
		{
			cout<<"List is empty. First add entries in list.\n\n";
			return;
		}
		
		string name;
		cout<<"Enter entry you wish to delete:\n";
		cin.ignore();
		getline(cin, name);
					
		int i,fnd=0,n=entries.size();
		
		//finding index of given entry
		for(i = 0; i < n; i++)
		{
			string s = entries[i].first.substr(entries[i].second,entries[i].first.size()-entries[i].second);
			if(s == name)
			{
				fnd = 1;
				break;
			}
		}
		
		//If not found in list,
		if(fnd == 0)
		{
			cout<<"No entries with given name exists\n";
			return;
		}
		
		int currLevel = entries[i].second;
		
		//Finding all its child
		int j = i+1;
		while(j<n && entries[j].second>currLevel)
			j++;
		
		//deleting entry and all its child	
		entries.erase(entries.begin()+i,entries.begin()+j);
		
		n=entries.size();
		if(n)
			lastAddedLevel = entries[n-1].second;
		else
			lastAddedLevel = 0;	
			
		cout<<"Entry deleted successfully.\n";
		printEntries();	
	}
	
	//Function to print Entire List
	void printEntries()
	{
		cout<<"Current List of Entries : \n\n";
		for(int i=0;i<entries.size();i++)
		{
			cout<<entries[i].first<<","<<entries[i].second<<"\n";	
		}	
		cout<<"\n";
	}			
};


int main()
{
	teachersTool maths = teachersTool();
	while(1)
	{
		cout<<"\nWhat would you like to do:\n";
		cout<<"1)Add new entry\n";
		cout<<"2)Indent entry\n";
		cout<<"3)Outdent entry\n";
		cout<<"4)Delete entry\n";
		cout<<"5)Exit\n";
		cout<<"\nEnter your choice: ";
		
		int a;
		cin>>a;
		switch(a)
		{
			case 1:
				maths.addEntry();
				break;				
				
			case 2:
				maths.indentEntry();
				break;				
				
			case 3:
				maths.outdentEntry();
				break;
							
			case 4:
				maths.deleteEntry();
				break;
							
			case 5:
				return 0;
				
			default:
				cout<<"Please enter number from 1-5 only.\n";		
		}
	}
	return 0;
}
