
#ifndef CONTAINER_H
#define CONTAINER_H
using namespace std;
template<typename T>
class Container
{
public:
    // ����������� ����������
    virtual ~Container() {};

    /*
     * ����������� ������, ������ ���� ����������� ����� �����������
     */

     // ������� ��������
    virtual void insert(const T& value) = 0;

    // �������� ��������
    virtual void remove(const T& value) = 0;

    // �������� ������� ��������
    virtual bool exists(const T& value) const = 0;
};

#endif // CONTAINER_H