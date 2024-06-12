// rapidjson/example/simpledom/simpledom.cpp`
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <iostream>

using namespace rapidjson;

int main() {
    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    {
        Value& s = d["stars"];
        s.SetInt(s.GetInt() + 1);
    }

    {
        //d["project"].SetString("SBS_ACADEMY");
        Value& s = d["project"];
        s.SetString("SBS_ACADEMY");
    }

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;

    // ���̺귯���� ���
    // - ���� �ڵ带 ���ϴ´�� ������ �� ������ ����� �� �ִ� ��.

 
    return 0;
}