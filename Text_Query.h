#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending = "s");

class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream& is) : file(new std::vector<std::string>)
{
	std::string text;
	while (std::getline(is, text))
	{
		file->push_back(text);
		auto n{ file->size() - 1 };
		std::istringstream line(text);
		std::string word;
		while (line >> word)
		{
			auto& lines = wm[word];
			if (!lines)
			{
				lines.reset(new std::set<line_no>);
			}
			lines->insert(n);
		}
	}
}

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s,
		std::shared_ptr<std::set<TextQuery::line_no>> p,
		std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f) {}
	std::set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
	std::set<TextQuery::line_no>::iterator end() { return lines->end(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

QueryResult TextQuery::query(const std::string& sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc{ wm.find(sought) };
	if (loc == wm.end())
	{
		return QueryResult(sought, nodata, file);
	}
	else
	{
		return QueryResult(sought, loc->second, file);
	}
}

std::ostream& print(std::ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << std::endl;
	for (auto num : *qr.lines)
	{
		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << std::endl;
	}
	return os;
}

std::string make_plural(size_t ctr, const std::string& word, const std::string& ending)
{
	return (ctr > 1) ? word + ending : word;
}

#endif // !TEXT_QUERY_H
