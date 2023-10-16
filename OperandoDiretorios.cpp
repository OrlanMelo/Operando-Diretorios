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
				cout << "O diretório foi criado com sucesso.\n";
			else
				cout << "Não foi possível criar o diretório..";
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
				cout << "O diretório principal e a árvore foi criada.\n";
			else
				cout << "Não foi possível criar a árvore de diretórios..";
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
			{
				_Remove_all_dir(Diretorio, codigo, max);
			}
			else
			{
				remove(Diretorio);
			}
		}
		catch (filesystem_error& erro)
		{
			cout << erro.what();
		}
	}

}Funcoes;

int main()
{

	cout << "O assistente está efetuando manipulações e tarefas no diretório...";

	Funcoes.CriarDiretorio((path)"C:\\teste2");
	Funcoes.CriarArvoreDeDiretorios((path)"C:\\Pai/subdir1/subdir2");
	Funcoes.RenomearDiretorio((path)"C:\\teste2", (path)"C:\\teste3");
	Funcoes.DeletarDiretorio((path)"C:\\teste3", false);

	system("pause");
}
