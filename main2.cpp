#include<fstream>
/*

Questo main può essere usato per clearare il file di tutti i  ";" . Anche se in realtà serve a ben poco, lo carico lo stesso

*/
using namespace std;

int main()
{
	fstream file("Punteggi.txt", ios::in | ios::out );
	fstream file2("Punti.txt",ios::in | ios::out | ios::app);
	for(int i = 0; i < 21; i++){
		string line;
		getline(file,line);
		int dim = line.length();
		for(int j = 0; j < dim ; j++)
		{
			if(line[j] == ';') file2 << " ";
			else file2  << line[j] ;
		}
		file2 << "\n";	
	}
	
	file.close();
	file2.close();
}
