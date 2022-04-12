

//#define B2
//#define B2_2
//#define B2_3
//#define B2_4
//#define B2_5
//#define B3_1
//#define B3_2
//#define B3_3
//#define B3_4
//#define B3_5
//#define B4_1
//#define B4_2
//#define B4_3
//#define B4_4
//#define B4_5
//#define B5_1
//#define B5_2
//#define B5_3
//#define B5_4
//#define B5_5
//#define B6_1
//#define B6_2
//#define B6_3
//#define B6_4
//#define B6_5
#define B7_1

#ifdef B2
#include <iostream>

int main() {
    int a;
    std::cin >> a; int max = a; int cnt_max = 0;
    while (a != 0) {
        if (a == max) ++cnt_max;

        if (a > max) {
            max = a;
            cnt_max = 1;
        }
        std::cin >> a;
    }
    if (cnt_max == 0) cnt_max = 1;
    std::cout << cnt_max;
    return 0;
}

#endif

#ifdef B2_2

#include <iostream>
#include <algorithm>
int main(){
    int *mas = new int[10]; int a; int i = 0; int *dist = new int[10];
    while(i < 10){ // input array
        std::cin >> a;
        mas[i] = a;
        ++i;
    }
    for (int h = 0; h < 10; ++h)
        if (mas[h] == 1) dist[h] = 1e2;
        else dist[h] = 0;

    for (i = 0; i < 10; ++i)
        std::cout << dist[i] << " ";
    std::cout << std::endl;
    for(int g = 0; g < 10; ++g){
        if (mas[g] == 1)
            for (int j = g + 1; j < 10; ++j)
                if (mas[j] == 2) {dist[g] = std::abs(j - g); break;}
    }

    for (int g = 9; g >= 0; --g){
        if (mas[g] == 1) {
            for (int j = g - 1; j >= 0; --j)
                if (mas[j] == 2) {dist[g] = std::min(std::abs(j - g), dist[g]); break;}
        }

    }
    int max = 0;
    for (i = 0; i < 10; ++i){
        std::cout << dist[i] << " ";
        if (max < dist[i]) max = dist[i];
    }
    std::cout << std::endl;

    std::cout << max;
    return 0;
}
#endif

#ifdef B2_3

#include <algorithm>
#include <iostream>
int price(const std::string& str);
int main(){
    std::string str;
    std::cin >> str;

    std::cout << price(str);
}

int price(const std::string& str){
    const unsigned int SIZE = str.size();
    int count = 0;
    for (int i = 0; i < SIZE / 2; ++i)
        if (str[i] != str[SIZE - i - 1])
            ++count;
    return count;
}
#endif

#ifdef B2_4

#include <iostream>
#include <vector>

int main(){
    int L, K ,a;
    int left, right, middle; left = middle = right = -1;

    std::cin >> L >> K;
    std::vector<int> mas;

    for (int i = 0; i < K; ++i){
        std::cin >> a;
        mas.push_back(a);
    }

    std::cout << std::endl;
    if (L % 2 == 1){
        for (int i = 0; i < K; ++i){
            if (mas[i] == L/2) middle = mas[i];
            if (mas[i] < L/2) left = mas[i];
            if (mas[i] > L/2 && right == -1) right = mas[i];
        }
    }
    else{
        for (int i = 0; i < K; ++i){
            if (mas[i] < L/2) left = mas[i];
            if (mas[i] >= L/2 && right == -1) right = mas[i];
        }
    }
    if (middle != -1){
        std::cout << middle << std::endl;
    }
    else{
        std::cout << left << " " << right << std::endl;
    }
    return 0;
}
#endif

#ifdef B2_5

#include <iostream>
#include <vector>

int main(){
    int N, a, max; std::cin >> N; max = 0;
    int S = 0;
    for (int i = 0; i < N; ++i){
        std::cin >> a;
        S += a;
        if (max < a) max = a;

    }
    std::cout << S - max;
}

#endif

#ifdef B3_1

#include <iostream>
#include <set>
#include <string>
#include <vector>
typedef int const_iterator;
std::vector<int> split (const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<int> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        res.push_back(std::stoi(token));
    }

    res.push_back (std::stoi(s.substr (pos_start)));
    return res;
}

int main(){
    std::set<int> mySet;
    std::set<int> mySet2;
    int a; size_t size = 100000; int cnt = 0;
    std::string line;
    std::getline(std::cin, line);
    std::vector<int> vec = split(line, " ");
    for(int i = 0; i < vec.size(); ++i){mySet.insert((vec[i]));}

    std::getline(std::cin, line);
    std::vector<int> vec2 = split(line, " ");
//    for(int i = 0; i < vec.size(); ++i){mySet2.insert((vec[i]));}

    for (int i = 0; i < vec2.size(); ++i){
        auto it = mySet.find(vec2[i]);
        if (it != mySet.end()){++cnt;}
    }
    std::cout << cnt;
    return 0;
}
#endif

#ifdef B3_2
#include <iostream>
#include <set>
#include <string>
#include <vector>

std::vector<int> split (const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<int> res;
    const size_t SIZE = s.size();
    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        res.push_back(std::stoi(token));
    }
    if (pos_start != SIZE)  res.push_back (std::stoi(s.substr (pos_start))); // last character is " " whitespace
    return res;
}

int main(){
    std::string line;
    std::set<int> mySet;
    std::getline(std::cin, line);
    if (line != ""){
        std::vector<int> vec = split(line, " ");


        for (int i = 0; i < vec.size(); ++i) {
            if (mySet.find(vec[i]) != mySet.end()) std::cout << "YES" <<std::endl;
            else {std::cout << "NO" << std::endl;
                mySet.insert(vec[i]);}

        }
    }
    else{
        std::cout << "incorrect input";
    }

    return 0;
}
#endif

#ifdef B3_3

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

std::vector<int> split (const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<int> res;
    const size_t SIZE = s.size();
    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        res.push_back(std::stoi(token));
    }
    if (pos_start != SIZE)  res.push_back (std::stoi(s.substr (pos_start))); // last character is " " whitespace
    return res;
}

int main(){
    std::string line;
    std::getline(std::cin ,line);

    std::vector<int> vec(split(line, " "));
    int max = 0; int min = 100000000;
    for (int i= 0; i < vec.size(); ++i) {if (max < vec[i]) max = vec[i]; if (min > vec[i]) min = vec[i];}

    if ( min <= 0){
        int cnt = 2 + max - min;
        std::vector<int> counter(cnt);
        for (int i = 0; i < vec.size(); ++i) {
            counter[vec[i] + std::abs(min)] += 1;}
        for (int i = 0; i < vec.size(); ++i) if (counter[vec[i] + std::abs(min)] == 1) std::cout << vec[i]  << " ";
        counter.clear();
        vec.clear();
    }
    else{
        int cnt = 2 + max - min;
        std::vector<int> counter(cnt);
        for (int i = 0; i < vec.size(); ++i) {
            counter[vec[i] - std::abs(min)] += 1;}
        for (int i = 0; i < vec.size(); ++i) if (counter[vec[i] - std::abs(min)] == 1) std::cout << vec[i]  << " ";
        counter.clear();
        vec.clear();
    }
    return 0;
}
#endif

/*std::vector<int> v_split (const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<int> res;
    const size_t SIZE = s.size();
    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        res.push_back(std::stoi(token));
    }
    if (pos_start != SIZE)  res.push_back (std::stoi(s.substr (pos_start))); // last character is " " whitespace
    return res;
}*/


#ifdef B3_4


#include<iostream>
#include<vector>
#include<set>
#include<string>
#include <algorithm>




std::set<int> split (const std::string& s, const std::string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::set<int> res;
    const size_t SIZE = s.size();
    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;

        res.insert(std::stoi(token));
    }
    if (pos_start != SIZE)  res.insert (std::stoi(s.substr (pos_start))); // last character is " " whitespace
    return res;
}



int main(){

    std::string str; std::getline(std::cin, str); int n = std::stoi(str) ;
    std::string str1; std::vector<int> vec;
    std::set<int> ban;
    std::set<int> intersect;
    std::set<int> intersect2;

    while(true) {
        std::getline(std::cin, str); if (str == "HELP") break;
        std::getline(std::cin, str1);

        if (str1 == "YES"){
            std::set<int> mySet(split(str, " "));

            if (intersect.empty()) intersect.insert(mySet.begin(), mySet.end());

            else {std::set_intersection(intersect.begin(), intersect.end(), mySet.begin(), mySet.end(), std::inserter(intersect2, intersect2.begin()));
            intersect.clear();
            intersect.insert(intersect2.begin(), intersect2.end());}
            intersect2.clear();
        }
        else{
            std::set<int> ban_set(split(str, " "));
            std::set_union(ban_set.begin(), ban_set.end(), ban.begin(),ban.begin(), std::inserter(ban, ban.begin()));
        }

    }
    std::vector<int> res;
    if(intersect.empty()) {
        for (int i = 1; i <= n; ++i) intersect.insert(i);
    }
    std::set_difference(intersect.begin(), intersect.end(), ban.begin(), ban.end(), std::inserter(res, res.begin()));
    for(int &i : res) if (i <= n) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

#endif

#ifdef B3_5

#include <iostream>
#include <unordered_set>
#include <vector>
#include <iterator>

template <typename T>
bool is_subset_of(const std::unordered_set<T>& a, const std::unordered_set<T>& b)
{
    // return true if all members of a are also in b
    if (a.size() > b.size())
        return false;

    auto const not_found = b.end();
    for (auto const& element: a)
        if (b.find(element) == not_found)
            return false;

    return true;
}

int main(){
    int M;     std::string str;
    std::getline(std::cin, str);
    M = std::stoi(str);
//    std::cin >> M;

    std::vector<std::unordered_set<char>> vec;

    for (int i =0; i < M; ++i){
        std::getline(std::cin , str);
        std::unordered_set<char> my_set(str.begin(), str.end());
        vec.push_back(my_set);
    }

    int N; std::getline(std::cin , str);
    N = std::stoi(str); std::vector<int> count (N);
    std::vector<std::string> vec2;
    for (int i = 0; i < N; ++i){
        std::getline(std::cin, str);
        std::unordered_set<char> my_set(str.begin(), str.end());
        vec2.push_back(str);
        for (int j = 0; j < M; ++j){
            if (is_subset_of(vec[j], my_set)) ++count[i];
        }

    }
    int max = 0;
    for (auto el:count) if(max < el) max = el;
    for (int j = 0; j < count.size(); ++j) if(count[j] == max) std:: cout << vec2[j] << std::endl;
}
#endif

#ifdef B4_1

#include <iostream>
#include <map>

int main(){

    std::map<int64_t, int64_t> map; std::string str;
    std::getline(std::cin, str); int N = std::stoi(str);
    for (int i = 0; i < N; ++i){
        int64_t key; std::cin >> key;
        int64_t val; std::cin >> val;
        if (map.find(key) == map.end())
            map[key] = val;
        else
            map[key] += val;

    }
    for (auto pair:map) std::cout << pair.first << " " << pair.second << std::endl;
    return 0;
}

#endif

#ifdef B4_2

#include <string>
#include <iostream>
#include <map>

int main(){
    std::string name; int count;
    std::map<std::string, int> map;
    while(!std::cin.eof()){
        std::cin >> name;
        std::cin >> count;
        if (map.find(name) == map.end())
            map[name] = count;
        else
            map[name] += count;

    }
    map[name] -= count;
    for (auto pair:map) std::cout << pair.first << " " << pair.second << std::endl;
    return 0;
}


#endif

#ifdef B4_3
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>


std::string::iterator start;
std::string str;

static auto cmp = [](std::pair<std::string, int> const & a, std::pair<std::string, int> const & b)
{
    return a.second != b.second?  a.second > b.second : a.first < b.first;
};

int main() {
//    std::string str;
    std::unordered_map<std::string, int> map;

    std::string str1;
    while (!std::getline(std::cin, str).eof()){
        start = str.begin();
        for (auto it = str.begin(); it < str.end(); ++it)
        {
            if (*it == ' ' || *it == '\n' || it == str.end() - 1)
            {

                if (it == str.end() - 1) std::copy( start,  it + 1 , std::inserter(str1, str1.begin()));
                else std::copy( start,  it , std::inserter(str1, str1.begin()));
                start = it + 1;
                map[str1] += 1;

                str1.clear();
            }

        }
    }

    std::vector<std::pair<std::string, int>> vector(map.begin(), map.end());
    std::sort(vector.begin(), vector.end() ,cmp);
    for (auto& el:vector) std::cout << el.first /*<< " " << el.second*/ << std::endl;
    return 0;
}
#endif

#ifdef B4_4

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>



std::string::iterator start_val;

static auto cmp = [](std::pair<std::pair<std::string, int>, double> const & a, std::pair<std::pair<std::string, int>, double> const & b)
{
    return a.second != b.second?  a.second > b.second : a.first.second > b.first.second;


};
bool is_all_equivalent(const std::vector<std::pair<std::string, int>>& vector){
    for (int i = 0; i < vector.size() - 1; ++i){
        if (vector[i].second != vector[i + 1].second) return false;
    }
    return true;
}
int main(){
    std::string str;
    std::string str2;
    int sum = 0;
    double nmb_party = 450;
    std::vector<std::pair<std::string, int>> map;
    while (!std::getline(std::cin, str).eof()){
        std::string str1;

        for (auto it = str.begin(); it < str.end(); ++it)
        {

            if ( std::isdigit(*it) && *(it - 1) == ' ') {
                start_val = it;
            }

        }
        std::copy(str.begin(), start_val - 1, std::inserter(str1, str1.begin()));
        int val;

            std::copy(start_val, str.end(), std::inserter(str2, str2.begin()));
            val = std::stoi(str2);
            sum += val;

        map.emplace_back(str1, val);
        str1.clear();
        str2.clear();

    }
    if (is_all_equivalent(map)){
        const int count = map.size();
        double vote_to_one_place = (static_cast<double>(sum)) / 450;
        for (int i = 0; i < map.size(); ++i)
            map[i].second = map[i].second / vote_to_one_place  ;
        for (auto & el : map){

            std::cout << el.first << ' ' << el.second << std::endl;
        }

        return 0;
    }

    std::vector<std::pair<std::pair<std::string, int>, double>> vec;
    int added_vote = 0;

    long double  vote_to_one_place = sum / nmb_party;
    for (int i = 0; i < map.size(); ++i){
        int res = map[i].second / vote_to_one_place;
        double residue = map[i].second - vote_to_one_place * res;
        map[i].second = res;
        added_vote += res;
        vec.emplace_back(std::make_pair(std::make_pair(map[i].first, map[i].second), residue));
    }

    std::sort(vec.begin(), vec.end(), cmp);
    int lack_vote = nmb_party - added_vote;

    if (!is_all_equivalent(map)){
        for (int i = 0; i < lack_vote; ++i){
            for (auto& el : map){
                if (el.first == vec[i].first.first)
                    ++el.second;
            }
        }
    }

    for (auto & el : map){

        std::cout << el.first << ' ' << el.second << std::endl;
    }


    return 0;
}

#endif

#ifdef B4_5
#include <iostream>
#include <vector>

bool is_int(const std::string& str){
    for (char it : str)
        if (!std::isdigit(it)) return false;
    return true;
}

int main(){
    std::string str;
    std::getline(std::cin, str);
    int N = std::stoi(str);
//    std::vector<std::pair<std::string, int>> vec;
    std::vector<std::vector<int>> cur_comments;
    std::vector<int> count;
    std::vector<std::string> name_topic;
    bool next_row_topic = false;
    int nmb_theme = 0;
    while (!std::getline(std::cin , str).eof()){
//        if (next_row_topic) {
//            name_topic.push_back(str);
//            next_row_topic = false;
//        }
        if (str[0] == '0'){
            std::vector<int> v;
            v.push_back(nmb_theme);
            cur_comments.push_back(v);
            count.push_back(1);
            next_row_topic = true;
            ++nmb_theme;
            std::getline(std::cin, str);
            name_topic.push_back(str);
            std::getline(std::cin, str);
        }
        else if(is_int(str)){
            int prev_comment = std::stoi(str) - 1;

            for (int i = 0; i < cur_comments.size(); ++i)
                for (int j = 0; j < cur_comments[i].size(); ++j)
                    if (cur_comments[i][j] == prev_comment){
                        cur_comments[i].push_back(nmb_theme);
                        ++count[i];
                    }


            ++nmb_theme;
            std::getline(std::cin, str);
        }

    }
    int max = 0; int ind_max = 0;
    for (int i = 0; i < count.size(); ++i){
        if (max < count[i]) {max = count[i]; ind_max = i;}
//        std::cout << count[i] <<"\t"<< name_topic[i] << std::endl;
    }
    std::cout << /*"most popular topic is\t" <<*/ name_topic[ind_max] << std::endl;
    return 0;
}

#endif

#ifdef B5_1
#include <iostream>
#include <vector>

int main(){
    int n, q, a, l, r;
//    std::cout << std::scientific << INT_MAX << std::endl;
    std::cin >> n >> q ;
    std::vector<int64_t> prefix;
    for (int i = 0; i < n; ++i){
        std::cin >> a;
        if (i == 0) prefix.push_back(a);
        else prefix.push_back(prefix[i - 1] + a);
    }
    for (int i = 0; i < n; ++i) std::cout << prefix[i] << "\t";
    for (int i = 0; i < q; ++i){
        std::cin >> l >> r;
        if (l - 1 == 0) std::cout << prefix[r - 1] << std::endl;
        else std::cout << prefix[r - 1] - prefix[l - 2] << std::endl;
    }
    return 0;
}

#endif

#ifdef B5_2
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

long long my_max(long long a, long long b, long long c){
    if (a >= b){
        if (a >= c)
            return a;
        else return c;
    }

    else{
        if (c > b) return c;
        else return b;
    }


}

long long max_difference(std::vector<long long>::iterator first, std::vector<long long>::iterator second){
    if(first == second) return LONG_LONG_MIN;
    if (first + 1 == second) return *first;
    if (first + 2 == second) {
        if (*first < 0) return *(second - 1) - *first;
        return std::max(*(second - 1), *first);
    }
    int64_t max = LONG_LONG_MIN;
    int64_t  min = LONG_LONG_MAX;
    std::vector<long long>::iterator it_min, it_max;
    for (auto it = first; it != second; ++it)
    {
        if (max < *it) {max = *it; it_max = it;}
        if (min > *it) {min = *it; it_min = it;}
    }
    if (min > 0) return max;
    if (it_min < it_max ) return max - min;
    else{


        return my_max(max_difference(first, it_max + 1), max_difference(it_max + 1, it_min), max_difference(it_min, second));
    }
    }


int main(){
    int n, a;
    std::cin >> n;
//    std::vector<long long> prefix(n + 1);
//    prefix[0] = 0;
    std::vector<long long> prefix;


    for (int i = 0; i < n; ++i)
    {
        std::cin >> a;
//        prefix[i] = (prefix[i - 1] + a);
        if (i == 0) prefix.push_back(a);
        else prefix.push_back(prefix[i - 1] + a);

    }
//        std::vector<long long> prefix;
//    for (int i = 0; i < n; ++i) {std::cin >> a; prefix.push_back(a);}


//    for (int i = 0; i < prefix.size(); ++i) std::cout << prefix[i] << "\t";
    std:: cout << max_difference(prefix.begin(), prefix.end()) << std::endl;
//    int64_t max = LONG_LONG_MIN, max2 = LONG_LONG_MIN;
//    int64_t min2 = LONG_LONG_MAX, min = LONG_LONG_MAX;
//    int ind_min; int ind_max;
//    for (int i = 0; i < n; ++i)
//    {
//        if (max < prefix[i]) {max = prefix[i]; ind_max = i;}
//        if (min > prefix[i]) {min = prefix[i]; ind_min = i;}
//    }
//    int64_t res;
//    for (int i = 0; i < ind_max; ++i)
//        if (min2 > prefix[i]) min2 = prefix[i];
//    for (int i = ind_min + 1; i < n; ++i)
//        if (max2 < prefix[i]) max2 = prefix[i];
//    if (min < 0){
//        if (ind_min < ind_max) res = max - min;
//        else if (max2)res = std::max(max2 - min, max - (min2 > 0 ? 0 : min2));
//    }
//    else res = max;
//    for (int i = 0; i < n; ++i) std::cout << prefix[i] << "\t";
//    std::cout << std::endl;
//    std::cout << res << std::endl;
    return 0;
}

#endif

#ifdef B5_3
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int N, M, a;
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> peoples;
    std::vector<std::pair<int, int>> computers;

    for (int i = 0; i < N; ++i)
    {
        std::cin >> a;
        peoples.push_back(std::make_pair(a, i + 1));
    }
    for (int i = 0; i < M; ++i){
        std::cin >> a;
        computers.push_back(std::make_pair(a, i + 1));
    }
    std::sort(peoples.begin(), peoples.end());
    std::sort(computers.begin(), computers.end());
    int last = computers.size() - 1; int last2 = peoples.size() - 1;
    std::vector<int> answer(N + 1);
    int count_group = 0;
    while ( last >= 0 && last2 >= 0){
        if (computers[last].first > peoples[last2].first){
//            std::cout << last + 1 << std::endl;
            answer[peoples[last2].second] = computers[last].second ;
            --last;
            --last2;
            ++count_group;
        }
        else if (computers[last].first <= peoples[last2].first){
//            std::cout << 0 <<std::endl;
            answer[peoples[last2].second] = 0;
            --last2;
        }

    }
    answer[0] = count_group;
    for(int el : answer)
        std::cout << el << std::endl;
    return 0;
}

#endif

#ifdef B5_4
#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string str;
    std::getline(std::cin , str);
    int is_correct_bracket_expression = 0;
    auto it = str.begin();
    while (it != str.end() && is_correct_bracket_expression >= 0)
    {

        if(*it == '(')
            ++is_correct_bracket_expression;
        if(*it == ')')
            --is_correct_bracket_expression;
        ++it;
    }
    if (!is_correct_bracket_expression)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}


#endif


#ifdef B5_5
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

std::tuple<int,int,int> search_fixed_sum(const std::vector<std::pair<int,int>>& A, const std::vector<std::pair<int,int>>& B, const std::vector<std::pair<int,int>>& C, int SUM){
    int S = SUM; int lenA = A.size(); int lenB = B.size(); int lenC = C.size();
    std::tuple <int, int, int> res(-1, -1, -1); bool is_cheking_before = false;
    for (int i = 0; i < lenA; ++i){
        int cur_sum = S - A[i].first;
        int left = 0; int right = C.size() - 1;
        while (left < B.size() && right >= 0){
            if (B[left].first + C[right].first > cur_sum){
                --right;
            }
            if (B[left].first + C[right].first < cur_sum){
                ++left;
            }
            if (B[left].first + C[right].first == cur_sum){
                if (is_cheking_before){
                    if (std::get<0>(res) > A[i].second)
                        res = std::make_tuple(A[i].second, B[left].second, C[right].second);
                    else if (std::get<0>(res) == A[i].second && std::get<1>(res) > B[left].second) res = std::make_tuple(A[i].second, B[left].second, C[right].second);
                    else if (std::get<0>(res) == A[i].second && std::get<1>(res) == B[left].second && std::get<2>(res) > C[right].second) res = std::make_tuple(A[i].second, B[left].second, C[right].second);

                }
                else {res = std::make_tuple(A[i].second, B[left].second, C[right].second); is_cheking_before = true;}
                if (right) --right;
                else ++left;
            }
        }

    }
    return res;

}
int main(){
    int lenA, lenB, lenC, S, el;
    std::vector<std::pair<int,int>> A; std::vector<std::pair<int,int>> B; std::vector<std::pair<int,int>> C;
    std::cin >> S;
    std::cin >> lenA;
    for(int i = 0; i < lenA; ++i){
        std::cin >> el;
        A.emplace_back(el, i);
    }
    std::cin >> lenB;
    for(int i = 0; i < lenB; ++i){
        std::cin >> el;
        B.emplace_back(el, i);
    }
    std::cin >> lenC;
    for(int i = 0; i < lenC; ++i){
        std::cin >> el;
        C.emplace_back(el, i);
    }
    std::sort(A.begin(), A.end()); std::sort(B.begin(), B.end()); std::sort(C.begin(), C.end());
    std::tuple<int,int,int> t(search_fixed_sum(A, B, C, S));
    if (std::get<0>(t) == -1) std::cout << -1;
    else std::cout << std::get<0>(t) << "\t"<< std::get<1>(t) << "\t" << std::get<2>(t) << std::endl;
    return 0;
}

#endif

#ifdef B6_1

#include <iostream>
#include <vector>
#include <algorithm>

int lbinsearch(const std::vector<int>& data, int search_el){
    int L = 0; int R = data.size() - 1;
    while (L < R){
        int m = (L + R) / 2;
        if (data[m] >= search_el) R = m;
        else L = m + 1;
    }
    if (data[L] < search_el) return -1;
    return L;
}
int rbinsearch(const std::vector<int>& data, int search_el){
    int L = 0; int R = data.size() - 1;
    while (L < R){
        int m = (L + R + 1) / 2;
        if (data[m] <= search_el) L = m;
        else R = m - 1;
    }
    if (data[L] > search_el) return -1;
    return L;
}
int main(){
    int N, K, L, R, el;
    std::vector<int> data;
    std::cin >> N;
    for (int i = 0; i < N; ++i){std::cin >> el; data.push_back(el);}
    std::sort(data.begin(), data.end());
    std::cin >> K;
    for (int i = 0; i < K; ++i){
        std::cin >> L >> R;
//        std::cout << lbinsearch(data, L) << "\t";
//
//        std::cout << rbinsearch(data, R);
//        std::cout << std::endl;
    int lvalue = lbinsearch(data, L);
    int rvalue = rbinsearch(data, R);
    if ((lvalue == -1) || (rvalue == -1)) {std::cout << 0 << "\t";}
    else std::cout << rbinsearch(data, R) + 1 - lbinsearch(data, L) << "\t";

    }
    return 0;
}

#endif

#ifdef B6_2
#include <iostream>
#include <vector>

int lbinsearch(const std::vector<int>& data, int search_el){
    int L = 0; int R = data.size() - 1;
    while (L < R){
        int m = (L + R) / 2;
        if (data[m] >= search_el) R = m;
        else L = m + 1;
    }
    if (data[L] != search_el) return -1;
    return L;
}
int rbinsearch(const std::vector<int>& data, int search_el){
    int L = 0; int R = data.size() - 1;
    while (L < R){
        int m = (L + R + 1) / 2;
        if (data[m] <= search_el) L = m;
        else R = m - 1;
    }
    if (data[L] != search_el) return -1;
    return L;
}

int main(){
    int N, M, el;
    std::vector<int> data;
    std::cin >> N;
    for (int i = 0; i < N; ++i){
        std::cin >> el;
        data.push_back(el);
    }
    std::cin >> M;
    for (int i = 0; i< M; ++i)
    {
        std::cin >> el;
        int lvalue = lbinsearch(data, el);
        int rvalue = rbinsearch(data, el);
        if ((lvalue == -1) || (rvalue == -1)) {std::cout << 0 << "\t" << 0 << std::endl;}
        else std::cout << lvalue + 1 << "\t" << rvalue + 1 << std::endl;
    }
    return 0;
}

#endif

#ifdef B6_3

#include <bits/stdc++.h>
typedef long double LD;
LD function(LD a, LD b, LD c, LD d, LD x){
//    return a * std::pow(x, 3) + b * std::pow(x, 2) + c * x + d;
    return a * x * x * x + b * x * x + c * x + d;
}
LD derivative_function(LD a, LD b, LD c, LD d, LD x){
    return (a * 3) * std::pow(x, 2) + 2*b * std::pow(x, 1) + c;
}
std::pair<LD, LD> solve_quadratic_equation(LD a, LD b, LD c){
    LD x1, x2, discriminant;
    discriminant = b*b - 4*a*c;
    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2*a);
        x2 = (-b - sqrt(discriminant)) / (2*a);
        if (x1 < x2) return std::make_pair(x1, x2);
        else return std::make_pair(x2, x1);

    }

    else if (discriminant == 0) {
        x1 = -b/(2*a);
        return std::make_pair(x1, x1);
    }

    else {
        return std::make_pair(LDBL_MAX, LDBL_MAX);
    }
}
LD bin_search(LD a, LD b, LD c, LD d, LD L, LD R){
//    LD L = 500;
//    LD R = 2000;
    LD eps = 1e-6;
    LD val;
    LD m = (L + R) / 2;
    int i = 0;
    while (std::abs(L - R) > 2 * eps){
        m = (L + R) / 2;
        val = function(a, b, c, d, m);
        LD derivative = derivative_function(a, b, c, d, m);
        if (val > std::pow(eps, 4)){
            if (derivative > 0)
                R = m;
            else
                L = m;
        }

        else if (val < -std::pow(eps, 4)){
            if (derivative > 0)
                L = m;
            else
                R = m;
        }
        if (val == 0){
            return L;
        }
//        if (i < 1000){
//            std::cout << "{number " << i <<"} {value " << val << "} {left " << L <<"} {right " << R << std::endl;
//            ++i;
//        }

    }

    return m;
}

LD find_solution(LD a, LD b, LD c, LD d){
    std::pair<LD, LD> res(solve_quadratic_equation(3 * a, 2 * b, c));
    if (res.first == res.second == LDBL_MAX){
        return bin_search(a, b, c, d, -1e4, 1e4);
    }
    else if (res.first == res.second) {
        return bin_search(a, b, c, d, -1e9, 1e9);
    }
    else {
        LD min = std::min(function(a, b, c, d, res.first), function(a, b, c, d, res.second));
        LD max = std::max(function(a, b, c, d, res.first), function(a, b, c, d, res.second));
        LD null = 1e-24;
        if (max < -null) {
            if (a > 0) {
                LD third_branch = bin_search(a, b, c, d, res.second, 1e9);
                return third_branch;
            } else {
                LD first_branch = bin_search(a, b, c, d, -1e9, res.first);
                return first_branch;
            }
        } else if (min > null) {
            if (a > 0) {

                LD first_branch = bin_search(a, b, c, d, -1e9, res.first);
                return first_branch;
            } else {
                LD third_branch = bin_search(a, b, c, d, res.second, 1e9);
                return third_branch;
            }
        }
    }
}

int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (d == 0){
        std::cout << 0;
    }
    else{
       std::cout << find_solution(a, b, c, d);
    }

    return 0;
}

#endif

#ifdef B6_4
//#include<bits\stdc++.h>
#include <iostream>
#include <cstdint>
using namespace std;
typedef uint64_t ll;
ll K, M, X;
int A, B;

ll sum(ll nmb_day){
    return (nmb_day/M) * ((M - 1) * B) + (nmb_day/K) * ((K - 1) * A) + (nmb_day % M) * B + (nmb_day % K) * A;
}
int main(){

    cin >> A >> K >> B >> M >> X;
    ll L = 0; ll R = 1e18/ std::max(A, B); ll m;

    while (L < R){
        m = (L + R) / 2;
        if (sum(m) >= X)
            R = m;
        else L = m + 1;
//        cout << L << "\t" << R << "\t";
    }
    std::cout << L << endl;

    return 0;
}

#endif

#ifdef B6_5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, el;

bool cover_all_point(int l, vector<int>& x){
    vector<bool> is_covering(n); int count = 0;
    for (int i = 0; i < n; ++i){
        if (!is_covering[i]){
            is_covering[i] = true;
            int j = i + 1;
            while (x[j] - x[i] <= l && j < n){
                is_covering[j] = true;
                ++j;
            }
            ++count;
        }
    }
    if (count <= k) return true;
    else return false;
}
int main(){
    vector<int> x;
    cin >> n >> k;

    for (int i = 0; i < n; ++i){
        cin >> el;
        x.push_back(el);
    }
    std::sort(x.begin(), x.end());
    int L = 0; int R = 2e9;
    while (L < R){
        int m = (L / 2 + R / 2);
        if (cover_all_point(m, x)){
            R = m;
        }
        else{
            L = m + 1;
        }
    }
    cout << L;
    return 0;
}

#endif

#ifdef B7_1
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int L, R, N;
    cin >> N ;
    vector<int> Larr;
    vector<int> Rarr;
    for (int j = 0; j < N; ++j){
        cin >> L >> R;
        int first_collision = -1;
        bool is_joined = false;
        int i = 0;
        while (i < Larr.size()){
            if ((Larr[i] <= L) && (L <= Rarr[i]) && (Larr[i] <= R) && (R <= Rarr[i])){
                is_joined = true;
                break;
            }

            else if ((Larr[i] <= L) && (L <= Rarr[i]) && (Rarr[i] < R)){
                if (first_collision != -1){
                    Larr[first_collision] = Larr[i];
                    Larr.erase(Larr.begin() + i);
                    Rarr.erase(Rarr.begin() + i);
                }
                else{
                    Rarr[i] = R;
                    first_collision = i;
                    ++i;
                }

                is_joined = true;
            }
            else if ((Larr[i] <= R) && (R <= Rarr[i]) && (L < Larr[i])){
                if (first_collision != -1){
                    Rarr[first_collision] = Rarr[i];
                    Larr.erase(Larr.begin() + i);
                    Rarr.erase(Rarr.begin() + i);
                }
                else{
                    Larr[i] = L;
                    first_collision = i;
                    ++i;
                }

                is_joined = true;
            }
            else if (Larr[i] > L && Rarr[i] < R){
                   Larr.erase(Larr.begin() + i);
                   Rarr.erase(Rarr.begin() + i);
            }
            else ++i;
        }
        if (!is_joined) {
            Larr.push_back(L);
            Rarr.push_back(R);
        }
    }
    int Sum = 0;
    for (int i = 0; i < Larr.size(); ++i){
        Sum += Rarr[i] - Larr[i];
    }
    cout << Sum;
    return 0;
}
#endif

