#include "MapLoader.h"
#include <fstream>
#include <string>

void MapLoader::Load(string filename)
{
	
	ifstream file(filename);

	

	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (!mapExist) 
			{
				if (line == "<Map>")
				{
					mapExist = true;
					cout << line << endl;
					continue;
				}
				else
				{
					cout << "Map document is not valid!" << endl;
					break;
				}
			}
			
				if (mapExist)
				{
					ContentExtract(line);
					
					if (line == "</Map>")
					{
						cout << line << endl;
						cout << "The end of the map!" << endl;
						cout << endl;
						break;
					}
					
				}
				
			
		}

		file.close();
	}
	else
	{
		cout << "Unable to open document! " << endl;
	}
}

void MapLoader::ContentExtract(string& line)
{
	int start = line.find(" ");
	int end = line.rfind(" ");
	if (start != string::npos && end != string::npos)
	{
		string content = line.substr(start, end - start);
		cout << content << endl;
	}
	else
	{
		cout << "Error ContentExtract 00005fB!" << endl;
	}

}

 