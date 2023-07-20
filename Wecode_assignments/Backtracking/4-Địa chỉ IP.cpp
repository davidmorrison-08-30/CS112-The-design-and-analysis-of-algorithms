#include <iostream>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

void print(vector<string> kq)
{
	for (int i = 0; i < kq.size(); i++)
		cout << kq[i] << endl;
}


void ExtractIP(string ip, vector<string>& output_ip, string temp="", int ind=0, int count=0)
{
	if (ip.size() == ind && count == 4)
	{
		temp.pop_back();
		output_ip.push_back(temp);
	}

	if (ip.size() >= (ind + 1))
	{
		temp = temp + ip.substr(ind, 1) + '.';
		ExtractIP(ip, output_ip, temp, ind + 1, count + 1);
		temp.erase(temp.end() - 2, temp.end());

		if (ip.size() >= (ind + 2) && ip[ind] != '0')
		{
			temp = temp + ip.substr(ind, 2) + '.';
			ExtractIP(ip, output_ip, temp, ind + 2, count + 1);
			temp.erase(temp.end() - 3, temp.end());

			if (ip.size() >= ind + 3 && stoi(ip.substr(ind, 3)) <= 255)
			{
				temp = temp + ip.substr(ind, 3) + '.';
				ExtractIP(ip, output_ip, temp, ind + 3, count + 1);
				temp.erase(temp.end() - 4, temp.end());
			}
		}
	}
}

int main() 
{
	string inp_str;
	vector<string> output_ip;
	cin >> inp_str;
	ExtractIP(inp_str, output_ip);
	print(output_ip);
	return 0;
}