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

int main(int argc,char* argv[])
{
	assert(argc >= (int)Argument::Num);

	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter converter;
	converter.ConvertTextureWICToDDS(argv[(int)Argument::FilePath]);

	CoUninitialize();

	system("pause");
	return 0;
}