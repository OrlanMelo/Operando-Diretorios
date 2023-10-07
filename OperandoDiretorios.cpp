#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
using namespace filesystem;

class cFuncoes
{
private:
public:

	void CriarDiretorio(path& Diretorio)
	{
		try
		{
			if (create_directory(Diretorio) == true)
				cout << "O diret�rio foi criado com sucesso.\n";
			else
				cout << "N�o foi poss�vel criar o diret�rio..";
		}
		catch (filesystem_error& erro)
		{
			cout << erro.what();
		}
	}

	void CriarArvoreDeDiretorios(path& Arvore)
	{
		try
		{
			if (create_directories(Arvore) == true)
				cout << "O diret�rio principal e a �rvore foi criada.\n";
			else
				cout << "N�o foi poss�vel criar a �rvore de diret�rios..";
		}
		catch (filesystem_error& erro)
		{
			cout << erro.what();
		}
	}

	void RenomearDiretorio(path& Antes, path& Novo)
	{
		try
		{
			rename(Antes, Novo);
		}
		catch (filesystem_error& erro)
		{
			cout << erro.what();
		}
	}

	void DeletarDiretorio(path& Diretorio, bool IncluirSubdiretorios)
	{
		try
		{
			uintmax_t max;
			error_code codigo;

			if (IncluirSubdiretorios == true)
				_Remove_all_dir(Diretorio, codigo, max);
			else
				remove(Diretorio);
		}
		catch (filesystem_error& erro)
		{
			cout << erro.what();
		}
	}

}Funcoes;

int main()
{

	cout << "O assistente est� efetuando manipula��es e tarefas no diret�rio...";

	Funcoes.CriarDiretorio((path)"C:\\teste2");
	Funcoes.CriarArvoreDeDiretorios((path)"C:\\Pai/subdir1/subdir2");
	Funcoes.RenomearDiretorio((path)"C:\\teste2", (path)"C:\\teste3");
	Funcoes.DeletarDiretorio((path)"C:\\teste3", false);

	system("pause");
}