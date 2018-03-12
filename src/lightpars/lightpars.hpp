#ifndef _LIGHTPARS_INCLUDED_
#define _LIGHTPARS_INCLUDED_

#include <string>
#include <vector>

namespace lightparse
{

class ParameterBase;

class Parser
{
public:
    using KeyValsArray = std::vector< std::pair<std::string, std::string> >;

    Parser();
    void parseCmdline(int argc, const char** argv);
    void addParameter(ParameterBase& parameter);

    const KeyValsArray& keyValsArray();

private:
    void splitCmdline(int argc, const char** argv);

    // parameters array
    KeyValsArray m_keyVals;
};

class ParameterBase
{
public:
    virtual ~ParameterBase() {}

    virtual std::string& valueToStr() = 0;
    virtual void parseStr(const std::string& str) = 0;

    std::string fullName;
    std::string shortName;
    std::string help;
};

template<typename T>
class Parameter : public ParameterBase
{
public:
    std::string& valueToStr() override;
    void parseStr(const std::string& str) override;

private:
    T value;
};

}

#endif // _LIGHTPARS_INCLUDED_
