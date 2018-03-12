#include "lightpars.hpp"

using namespace lightparse;

/*
 * ./my-program --parameter1=25 \t -v      48 --parameter2 "input.txt"
*/

Parser::Parser()
{
    // Nothing
}

void Parser::parseCmdline(int argc, const char** argv)
{
    splitCmdline(argc, argv);
    // ...
}

void Parser::addParameter(ParameterBase& parameter)
{
}

const Parser::KeyValsArray& Parser::keyValsArray()
{
    return m_keyVals;
}

void Parser::splitCmdline(int argc, const char** argv)
{
    // Fill m_keyVals
}
