#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
n자리 숫자의 제곱 수 2n-1 ~ 2n
800자리 수가 제곱이려면
400자리 수여야 한다
*/

class bigInt
{
private:
    string value;

public:
    bigInt() : value("0") {}

    bigInt(string str)
    {
        value = str;
    }

    int length()
    {
        return value.size();
    }

    void removeLeadingZeros()
    {
        while (value.size() > 1 && value[0] == '0')
        {
            value.erase(0, 1);
        }
    }

    void half()
    {
        int len = -1;
        int take = 0;
        while (++len < value.size())
        {
            if ((value[len] - '0') % 2 == 1)
            {
                value[len] = ((take * 10 + value[len] - '0') / 2) + '0';
                take = 1;
            }
            else
            {
                value[len] = ((take * 10 + value[len] - '0') / 2) + '0';
                take = 0;
            }
        }
        removeLeadingZeros();
    }

    bigInt shiftLeft(int n) const
    {
        bigInt result = *this; // 현재 값을 복사
        for (int i = 0; i < n; i++)
        {
            result.value += '0'; // 문자열 끝에 '0' 추가 (10배씩 곱하는 효과)
        }
        return result; // 새로운 `bigInt` 반환
    }

    bigInt operator*(const bigInt &other) const
    {
        bigInt result = multiply(value, other.value);
        result.removeLeadingZeros();
        return result;
    }
    bigInt operator+(const bigInt &other)
    {
        bigInt result = Add(value, other.value);
        result.removeLeadingZeros();
        return result;
    }
    bigInt operator-(const bigInt &other)
    {
        bigInt result = subtract(value, other.value);
        result.removeLeadingZeros();
        return result;
    }

    bool operator>(const bigInt &other)
    {
        if (value.size() > other.value.size())
            return true;
        else if (value.size() < other.value.size())
            return false;
        else
        {
            for (int i = 0; i < value.size(); i++)
            {
                if (value[i] > other.value[i])
                    return true;
                else if (value[i] < other.value[i])
                {
                    return false;
                }
            }
        }
        return false;
    }
    bool operator<(const bigInt &other)
    {
        if (value.size() < other.value.size())
            return true;
        else if (value.size() > other.value.size())
            return false;
        else
        {
            for (int i = 0; i < value.size(); i++)
            {
                if (value[i] < other.value[i])
                    return true;
                else if (value[i] > other.value[i])
                {
                    return false;
                }
            }
        }
    }
    bool operator==(const bigInt &other)
    {
        if (value.size() != other.value.size())
            return false;

        for (int i = 0; i < value.size(); i++)
        {
            if (value[i] != other.value[i])
                return false;
        }
        return true;
    }

    friend ostream &operator<<(ostream &os, const bigInt &num)
    {
        os << num.value;
        return os;
    }

private:
    static bigInt Add(const string &num1, const string &num2)
    {
        string result = "";
        int carry = 0, sum;
        int i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry)
        {
            sum = carry;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';
            carry = sum / 10;
            result += (sum % 10) + '0';
        }

        reverse(result.begin(), result.end());
        return bigInt(result);
    }

    static bigInt multiply(const string &num1, const string &num2)
    {
        int len1 = num1.size(), len2 = num2.size();
        if (len1 < 10 || len2 < 10)
        { // 작은 수는 기본 곱셈 사용
            return bigInt(to_string(stoll(num1) * stoll(num2)));
        }

        int mid = max(len1, len2) / 2;

        bigInt high1(num1.substr(0, len1 - mid));
        bigInt low1(num1.substr(len1 - mid));
        bigInt high2(num2.substr(0, len2 - mid));
        bigInt low2(num2.substr(len2 - mid));

        bigInt z0 = low1 * low2;
        bigInt z1 = (low1 + high1) * (low2 + high2);
        bigInt z2 = high1 * high2;

        return (z2.shiftLeft(2 * mid) + ((z1 - z2 - z0).shiftLeft(mid)) + z0);
    }

    static bigInt subtract(const string &num1, const string &num2)
    {
        string result = "";
        int borrow = 0, diff;
        int i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0)
        {
            diff = (num1[i] - '0') - borrow;
            if (j >= 0)
                diff -= (num2[j--] - '0');

            if (diff < 0)
            {
                diff += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
            result += (diff + '0');
            i--;
        }

        reverse(result.begin(), result.end());
        bigInt res(result);
        res.removeLeadingZeros();
        return res;
    }
};

bigInt binSearch(string target)
{
    bigInt N(target);
    if (N == bigInt("1"))
        return bigInt("1");

    bigInt lower("1");
    bigInt upper(target);
    bigInt ans;

    while (lower < upper)
    {
        bigInt now = lower + upper;
        now.half(); // now = (lower + upper) / 2

        // 🚀 개선된 부분: 자리수 비교 먼저 수행
        int lenN = target.size();
        int lenNow = now.length();
        if (2 * lenNow < lenN)
        { // now^2이 너무 작으면 바로 lower 증가
            lower = now + bigInt("1");
            continue;
        }
        else if (2 * lenNow > lenN + 2)
        { // now^2이 너무 크면 upper 감소
            upper = now - bigInt("1");
            continue;
        }

        bigInt nowsqr = now * now; // 최적화 후 비교
        if (N == nowsqr)
            return now;
        else if (N < nowsqr)
            upper = now - bigInt("1");
        else
            lower = now + bigInt("1");
    }

    if (lower == upper)
    {
        bigInt sqr = lower * lower;
        if (sqr == N)
            return lower;
    }

    // cout << "Error!" << target << " " << lower << " " << upper << endl;
    return bigInt();
}

void checker()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    long long i = 1;
    while (true)
    {
        if (i % 100000 == 0)
            cout << i << endl;
        long long isqr = i * i;
        long long orig = i;
        string origin = "";
        string sqr = "";
        while (orig > 0)
        {
            origin += (orig % 10) + '0';
            orig /= 10;
        }
        while (isqr > 0)
        {
            sqr += (isqr % 10) + '0';
            isqr /= 10;
        }
        reverse(origin.begin(), origin.end());
        reverse(sqr.begin(), sqr.end());
        bigInt O(origin);
        bigInt answer = binSearch(sqr);
        if (O == answer)
        {
        }
        else
        {
            cout << "Q: " << orig << " " << isqr << endl;
            cout << "error! origin: " << origin << " answer: " << answer << endl;
            return;
        }
        i++;
    }
}

int main()
{
    // checker();
    // return 0;
    string num;
    cin >> num;

    cout << binSearch(num);

    return 0;
}