#pragma once


#include <string>
#include <string_view>



class IParagraph
{
public:
	virtual ~IParagraph() = default;
	virtual std::string getHTML() const = 0;
};


class Paragraph : public IParagraph
{
public:
	Paragraph(std::string_view str)
		:mstr(str)
	{}
	virtual std::string getHTML() const override { return mstr; }

private:
	std::string mstr;
};

class Bold : public IParagraph
{
public:
	Bold(const IParagraph& pa) : mp(pa) {}
	virtual std::string getHTML() const override { return "<B>" + mp.getHTML() + "</B>"; }

private:
	const IParagraph& mp;
};

class Italic : public IParagraph
{
public:
	Italic(const IParagraph& pa) : mp(pa) { }
	virtual std::string getHTML() const override { return "<I>" + mp.getHTML() + "</I>"; }

private:
	const IParagraph& mp;
};


