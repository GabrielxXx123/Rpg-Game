#include "MapLoader.h"
#include <fstream>
#include <string>
#include <sstream>
#include "Map.h"


// -----------------------------------------  IN DOC.XML ----------- All variables must start with space " " and finish with space " " ----------------------------------//
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
					

					if (line == "</Map>")
					{
						cout << line << endl;
						cout << "The end of the map!" << endl;
						cout << endl;
						break;
					}
				

					int start = line.find(" ");
					int end = line.rfind(" ");

					if (start != string::npos && end != string::npos && start < end)
					{
						tag = line.substr(0, start);
						value = line.substr(start  + 1 , end - start);
						
					}
					else
					{
						cout << "Error ContentExtract 00005fB!" << endl;
						
					}
					
					try {

						if (tag == "<name>")
						{
							mapNameXML = value;
						}
						else if (tag == "<tileWidth>")
						{
							tileWidthXML = stoi(value);
						}
						else if (tag == "<tileHeight>")
						{
							tileHeightXML = stoi(value);
						}
						else if (tag == "<totalTiles>")
						{
							totalTilesXML = stoi(value);
						}
						else if (tag == "<path>")
						{
							pathXML = value;
						}
						else if (tag == "<table>")
						{
							stringstream ss(value);
							int index = 0;

							while (ss >> cell) {
								
								int a = std::stoi(cell);

								
								if (index < tableLengthXML) {
									tableXML[index] = a;  
									index++;  
								}
								else if(ss.str().empty())
								{
									cout << "Error: Array is empty!" << endl;
									break;
								}
								else 
								{
									std::cout << "Error: Too many values for tableXML!" << std::endl;
									break; 
								}
							}
							
						}
			
						cout << "Data from doc.xml :" << value << endl;

					}
					catch(exception e)
					{
						cout << "Error from data declaration!" << endl;
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
		
		 string value = line.substr(start, end - start);
		
	}
	else
	{
		cout << "Error ContentExtract 00005fB!" << endl;
	}

}

