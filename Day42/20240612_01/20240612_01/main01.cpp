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

    // 라이브러리를 사용
    // - 예제 코드를 원하는대로 수정할 수 있으면 사용할 수 있는 것.

 
    return 0;
}