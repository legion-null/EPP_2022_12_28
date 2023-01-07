#pragma once

#include "base/Object/Object.h"

namespace Epp {
namespace io {

class File: public base::Object {

EPP_CLASS_INFO

private:
	static File *StandardInput;
	static File *StandardOutput;
	static File *StandardError;

public:
	static File& GetStandardInput();
	static File& GetStandardOutput();
	static File& GetStandardError();

protected:
	struct CFile *cfile = nullptr;
	u64 size = 0;
	u64 cur = 0;

private:
	File();

public:
	virtual ~File();

public:
	File(const base::String &path);

public:
	u64 getSize() const;

public:
	u64 getCur() const;
	void setCur(u64 cur);

public:
	void flush() const;

public:
	i32 readByte();
	void read(u8 *buf, u64 len);

public:
	void writeByte(u8 byte);
	void write(const u8 *buf, u64 len);
};

}
}

