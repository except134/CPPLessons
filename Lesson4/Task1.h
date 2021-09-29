#pragma once

class ArrayInt
{
public:
    ArrayInt() :
        m_length(0), m_data(nullptr)
    {}

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    int getLength() const { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength, int start_index = 0)
    {
        if (newLength == m_length)
            return;

        if (newLength <= 0) {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0) {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            if(start_index != 0)
                elementsToCopy ++;

            for (int index = start_index; index < elementsToCopy; ++index)
                data[index - start_index] = m_data[index];
        }

        delete[] m_data;

        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length+1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;

        m_data = data;
        ++m_length;
    }

    void push_back(int value) { insertBefore(value, m_length); }

    int pop_back()
    {
        int ret = m_data[m_length];
        resize(m_length - 1);
        return ret;
    }

    int pop_front()
    {
        int ret = m_data[0];
        resize(m_length - 1, 1);
        return ret;
    }

    void Sort()
    {
        std::sort(&m_data[0],&m_data[m_length]);
    }

    void Print()
    {
        std::cout << "(";
        for(int index = 0; index < m_length; ++index) {
            if(index != 0)
                std::cout << ", ";
            std::cout << m_data[index];
        }
        std::cout << ")" << std::endl;
    }

private:
    int  m_length;
    int* m_data;
};
