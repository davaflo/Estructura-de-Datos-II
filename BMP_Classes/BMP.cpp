#include "BMP.h"

using namespace std;

void MyBitmap::readHeader() {
	file_bmp.seekg(0, ios_base::beg);
	
	file_bmp.read(bufferHeader_aux, sizeof(bufferHeader_aux));
	file_bmp.read(buffer_headerInfo_aux, sizeof(buffer_headerInfo_aux));
	

	bmpHeader.setHeaderBuffer(bufferHeader_aux);
	bmpHeader.setHeader_infoBuffer(buffer_headerInfo_aux);

	int inicio = bmpHeader.headerSize;
	int width = bmpHeader.imageWidth;
	int height = bmpHeader.imageHeight;

	//file_bmp.seekg(inicio);

	int imagesize = 0;
	width += (3 * width) & 4;//paddeo
	imagesize = 3 * width * height;
	int R = 0, G = 0, B =0;


}	

void MyBitmap::openBMP(const char* filename) 
{
	file_bmp.open(filename, ifstream::in | ifstream::binary);
	readHeader();
	
}

void MyBitmap::print_metaData() {

	cout << "**************************** H E A D E R *******************************" << endl;
	cout << "Signature: " << bmpHeader.signature << endl; 
	cout << "File Size: " << bmpHeader.fileSize << endl;
	cout << "Reserved 1: " << bmpHeader.Reserved_1 << endl;
	cout << "Reserved 2: " << bmpHeader.Reserved_2 << endl;
	cout << "Data Offset: " << bmpHeader.dataOffset << endl;
	cout << "**************************** I N F O  H E A D E R *******************************" << endl;
	cout << "Size: " << bmpHeader.headerSize << endl;
	cout << "Width: " << bmpHeader.imageWidth << endl;
	cout << "Height: " << bmpHeader.imageHeight << endl;
	cout << "Planes: " << bmpHeader.planes << endl;
	cout << "Bit Count: " << bmpHeader.bitsperPixel << endl;
	cout << "Compression: " << bmpHeader.compression << endl;
	cout << "Image Size: " << bmpHeader.imageSize << endl;
	cout << "X Pixels Per M: " << bmpHeader.xPixels << endl;
	cout << "Y Pixels Per M: " << bmpHeader.yPixels << endl;
	cout << "Colors Used: " << bmpHeader.totalColors << endl;
	cout << "Colors Important: " << bmpHeader.importantColors << endl;
	cout << "********************* C O L O R  P A L L E T E ***********************" << endl;




//diferencia entre economia de libre de mercado y economia planeada	

}

Headers::Headers()
{
	Init();
}

void Headers::setHeaderBuffer(const char* buffer)
{
	memcpy(bufferHeader, buffer, 14);
	unPack();
}
void Headers::setHeader_infoBuffer(const char* buffer) {
		memcpy(buffer_headerInfo, buffer, 40);
		unPack();
}

void Headers::setColorPallete_Buffer(const char * buffer) {
	memcpy(buffer_colorPallete, buffer, 4);
	unPack();
}

void Headers::Init()
{
	//header variables
	signature[2] = '\0';
	fileSize = 0;
	Reserved_1 = 0;
	Reserved_2 = 0;
	dataOffset = 0;
	//header info variables
	headerSize = 0 ;
	imageWidth = 0 ;
	imageHeight = 0 ;
	planes = 0 ;
	bitsperPixel = 0 ;
	compression = 0 ;
	imageSize = 0 ;
	xPixels = 0 ;
	yPixels = 0 ;
	totalColors = 0 ;
	importantColors = 0 ;
	//colors 
	RED = 0;
	GREEN = 0;
	BLUE = 0;
	RESERVED_4PADDING = 0;

}



void Headers::unPack() {
	char *c = bufferHeader;
	memcpy(&signature, c, 2);
	memcpy(&fileSize, c+=2, 4);
	memcpy(&Reserved_1, c+=4, 2);
	memcpy(&Reserved_2, c+=2, 2);
	memcpy(&dataOffset, c+=2, 4);
	//header Info
	char* d = buffer_headerInfo;
	memcpy(&headerSize, d, 4);
	memcpy(&imageWidth, d += 4 , 4);
	memcpy(&imageHeight, d += 4, 4);
	memcpy(&planes, d += 4, 2);
	memcpy(&bitsperPixel, d += 2, 2);
	memcpy(&compression, d += 2, 4);
	memcpy(&imageSize, d += 4, 4);
	memcpy(&xPixels, d += 4, 4);
	memcpy(&yPixels, d += 4, 4);
	memcpy(&totalColors, d += 4, 4);
	memcpy(&importantColors, d += 4, 4);

	char * e = buffer_colorPallete;
	memcpy(&BLUE, e, 1);
	memcpy(&GREEN, e +1, 1);
	memcpy(&RED, e +1, 1);
	memcpy(&RESERVED_4PADDING, e +1, 1);

}

