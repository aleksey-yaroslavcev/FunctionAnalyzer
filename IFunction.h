#pragma once

#include <vector>
#include <list>
#include <string>
#include <map>

class IFunction
{
protected:
	std::map<std::string, double> _params;
	std::string _description;

	virtual double GetValue(double x) = 0;
public:
	IFunction(){};
	~IFunction(){};
	unsigned int GetFunctionValues(std::vector<double>& array, double x1, double x2, double step);

	std::list<std::string> GetParamsList();
	void SetParam(std::string name, double val){ _params[name] = val; };
	std::string GetFunctionDescription(){ return _description; };
};

