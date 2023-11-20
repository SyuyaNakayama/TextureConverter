#include <cstdio>
#include <cstdlib>
#include <DirectXTex.h>
#include "TextureConverter.h"

// �R�}���h���C������
enum class Argument
{
	ApplicationPath,	// �A�v���P�[�V�����̃p�X
	FilePath,			// �n���ꂽ�t�@�C���̃p�X
	Num
};

int main(int argc, char* argv[])
{
	if (argc < (int)Argument::Num)
	{
		// �g������\������
		TextureConverter::OutputUsage();
		return 0;
	}

	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// �I�v�V�����̐�
	int numOptions = argc - (int)Argument::Num;
	// �I�v�V�����z��(�_�u���|�C���^)
	char** options = argv + (int)Argument::Num;

	TextureConverter converter;
	converter.ConvertTextureWICToDDS(argv[(int)Argument::FilePath], numOptions, options);

	CoUninitialize();
	return 0;
}