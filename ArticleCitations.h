#pragma once


#include <string>
#include <string_view>

class ArticleCitations
{
public:
	ArticleCitations(std::string_view fileName);
	virtual ~ArticleCitations();
	ArticleCitations(const ArticleCitations& src);
	ArticleCitations& operator=(const ArticleCitations& rhs);

	std::string_view getArticle() const { return mArticle; }
	int getNum() const { return mNums; }
	std::string_view getCitations(int i) const { return mCitations[i]; }


private:
	void readFile(std::string_view fileName);
	void copy(const ArticleCitations& src);

	std::string mArticle;
	std::string* mCitations;
	int mNums;
};