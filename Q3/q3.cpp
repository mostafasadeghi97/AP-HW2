#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>



//================= MOSTAFA SADEGHI   9423067 =============

int main()
{
    //reading from db.txt and save it to db_data
	std::ifstream file("db.txt");
	std::string  line;
	std::vector<std::vector<std::string>> db_data;

	while (std::getline(file, line))
	{
		std::vector<std::string> temp;
		std::istringstream ss(line);

        std::string name, var1, var2, var3;
        ss >> name >> var1 >> var2 >> var3;
        temp.push_back(name);
        temp.push_back(var2);
        temp.push_back(var3);
        db_data.push_back(temp);

	}
    //declaring required variables 
	std::map<std::string, int*> dict;
	std::map<std::string, int> product_id;
	std::map<std::string, int> product_id2;
	std::map<std::string, int> customer_id2;
	std::map<std::string, int> customer_id;
    for(size_t i{0};i < db_data.size();i++){
	   
    	
    	std::string a{db_data[i][0]};
    	if (dict.find(a) == dict.end()){

	    			
    		int init[]{1,1};
        	dict[a] = init; 			
        	product_id[a+db_data[i][1]] = 1;
        	customer_id[a+db_data[i][2]] = 1;
        	product_id2[a] = 1;
        	customer_id2[a] = 1;
    	}
    	else{
    		if (product_id.find(a + db_data[i][1]) == product_id.end()){
    			product_id[a+db_data[i][1]] = 1;
    			product_id2[a] += 1;
        		dict[a][0]+=1;
    		}
    		
    		if (customer_id.find(a + db_data[i][2]) == customer_id.end()){
    			customer_id[a+db_data[i][2]] = 1;
    			customer_id2[a] += 1;
    			dict[a][1]+=1;
    		}
    	}
    	
	}
    std::ofstream myfile;
    // start writing to dbnew.txt
    myfile.open ("dbnew.txt");

		for (const auto &p : product_id2) {

            if (p.first == "")
            {
                continue;
            }
            //print on console and write to dbnew.txt
        	std::cout << p.first << "] " << p.second << " " << customer_id2[p.first] <<'\n';
            myfile << p.first << "] " << p.second << " " << customer_id2[p.first] <<'\n';
	   }
	return 0;
}