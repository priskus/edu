#include <iostream>
#include <memory>
#include <cstring>

class String{
public:
    String() = default;
    String(const char* string ) //просто конструктор
    {
        printf("String Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data,string,m_Size);
    }

    String(const String &other) //конструктор копирования
    {
        //const ссылка может привязываться к rvalue
        //и если нет move constructor-а будет вызван этот копир. конструктор

        printf("String Copy constr!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data,other.m_Data,m_Size);//копирование содержимого
    }

    String& operator=(const String &other)//copy assignment operator
    {
        if(this != &other) {
            delete[] m_Data;
            printf("String Copy assignment operator!\n");
            m_Size = other.m_Size;
            m_Data = new char[m_Size];
            memcpy(m_Data, other.m_Data, m_Size);//копирование содержимого
        }
        return *this;
    }

    String(String &&other) : m_Size(other.m_Size), m_Data(other.m_Data) //конструктор перемещения
    {
        printf("String Move constr!\n");
        other.m_Data = nullptr;//обнуление старого указателя
        other.m_Size = 0;
    }

    String& operator=(String && other) noexcept//move assignment operator
    {
        if(this != &other)
        {
            printf("String Move assignment operator!\n");

            delete[] m_Data;

            m_Size = other.m_Size;
            m_Data = other.m_Data;//присвоим новому указателю значение старого

            other.m_Data = nullptr;//обнуление старого указателя
            other.m_Size = 0;
        }
        return *this;
    }

    ~String()
    {
//        printf("Destroyed\n");
        delete m_Data;
    }

    void Print(){
        for(uint32_t i = 0; i < m_Size; i++)
            printf("%c",m_Data[i]);
        printf("\n");
    }   //печать содержимого массива char*

private:
    char* m_Data{}; //?
    uint32_t m_Size{};
};

class Entity
{
public:
    Entity(const String& name):m_Name(name){} //String m_Name;
    //const ссылка может привязываться к rvalue
    //и если нет constructor-а для rvalue будет вызван этот копир. конструктор
    //так как ссылка const, ее содержимое нельзя менять, например, обнулить указатель
    //внутри, приходится только копировать

    //без явного преобразования (String&&)name будет вызван верхний констр.
    //(ведь если можно взять адрес, то это lvalue) : cout << &name<<endl;
    //но (String&&)name преобразование эквивалентно выражению move(name).
    //напишем конструктор от rvalue:
    //Entity(String&& name):m_Name((String&&)name){}
    //что эквивалентно следующему:

    Entity(String&& name):m_Name(std::move(name)){std::cout << &name<<std::endl;}
    //этот к. вызывает к. перемещения у String
    //тут name - lvalue, потому что имеет имя и адрес
    //хоть и имеет тип rvalue ref to String
    //
    //для вызова String(String &&other) нужно преобразовать name
    //к rvalue следующим образом: move(name)
    void PrintName(){
        m_Name.Print();
    }
private:
    String m_Name;
};

int main(){
    // const String& s = "asdf";

//    Entity entity(String("Content"));//или Entity entity("Content");
//    //сначала вызывается конструктор String(const char*)
//    //получаем rvalue String (временный объект)
//    //затем вызывается конструктор Entity(String&& name), который вызывает
//    // конструктор перемещения String(String&& other)
//    //перемещает временный объект типа String в поле типа String класса типа Entity
//    entity.PrintName();

     String str = "Hello";
     String dest = "No"; //эквивалентно String dest = (String&&)str;
    dest.Print();
     dest = str;
     dest.Print();
     str.Print();
//    String dest1(move(str)); //or like that

    // cout << endl;

    // String apple = "Apple";
    // String dest2;

    // cout << "Apple: ";
    // apple.Print();
    // cout << "Dest: ";
    // dest2.Print();

    // dest2 = move(apple);

    // cout << "Apple: ";
    // apple.Print();
    // cout << "Dest: ";
    // dest2.Print();

    return 0;
}