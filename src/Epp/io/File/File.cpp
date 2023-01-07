#include "Epp.h"

#include <stdio.h>

using namespace Epp::io;

using namespace Epp;
using namespace Epp::base;

namespace Epp {
namespace io {

const Class *File::ClassInfo = Class::Register<File, Object>("Epp::io::File", nullptr);

struct CFile {
	::FILE *fp = nullptr;
};

File *File::StandardInput = nullptr;
File *File::StandardOutput = nullptr;
File *File::StandardError = nullptr;

File& File::GetStandardInput() {
	if (StandardInput == nullptr) {
		StandardInput = new File();
		StandardInput->cfile->fp = stdin;
	}

	return *StandardInput;
}

File& File::GetStandardOutput() {
	if (StandardOutput == nullptr) {
		StandardOutput = new File();
		StandardOutput->cfile->fp = stdout;
	}

	return *StandardOutput;
}

File& File::GetStandardError() {
	if (StandardError == nullptr) {
		StandardError = new File();
		StandardError->cfile->fp = stderr;
	}

	return *StandardError;
}

File::File() {
	this->cfile = new struct CFile;
}

File::~File() {

}

File::File(const base::String &path) {
	this->cfile = new struct CFile;

	this->cfile->fp = ::fopen(path.getValue(), "a+");

	this->size = ::fseek(this->cfile->fp, 0, SEEK_END);
	setCur(0);
}

u64 File::getSize() const {
	return this->size;
}

u64 File::getCur() const {
	return this->cur;
}

void File::setCur(u64 cur) {
	this->cur = cur;
	::fseek(this->cfile->fp, this->cur, SEEK_SET);
}

void File::flush() const {
	::fflush(this->cfile->fp);
}

i32 File::readByte() {
	i32 c = ::fgetc(this->cfile->fp);

	if (c != EOF) {
		this->cur++;
	} else {
		Exception("Reached end of file");
	}

	return c;
}

void File::read(u8 *buf, u64 len) {
	u64 n = ::fread(buf, 1, len, this->cfile->fp);

	if (n != (u64)EOF) {
		this->cur += n;
	}
}

void File::writeByte(u8 byte) {
	if (::fputc(byte, this->cfile->fp) != EOF) {
		this->cur++;
	} else {
		Exception("Reached end of file");
	}
}

void File::write(const u8 *buf, u64 len) {
	if (::fwrite(buf, 1, len, this->cfile->fp) != (u64)EOF) {
		this->cur += len;
	} else {
		Exception("Error");
	}
}

}
}
