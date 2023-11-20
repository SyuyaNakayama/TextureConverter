#include <cstdio>
#include <cstdlib>
#include <DirectXTex.h>
#include "TextureConverter.h"

// コマンドライン引数
enum class Argument
{
	ApplicationPath,	// アプリケーションのパス
	FilePath,			// 渡されたファイルのパス
	Num
};

int main(int argc, char* argv[])
{
	if (argc < (int)Argument::Num)
	{
		// 使い方を表示する
		TextureConverter::OutputUsage();
		return 0;
	}

	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	assert(SUCCEEDED(hr));

	// オプションの数
	int numOptions = argc - (int)Argument::Num;
	// オプション配列(ダブルポインタ)
	char** options = argv + (int)Argument::Num;

	TextureConverter converter;
	converter.ConvertTextureWICToDDS(argv[(int)Argument::FilePath], numOptions, options);

	CoUninitialize();
	return 0;
}