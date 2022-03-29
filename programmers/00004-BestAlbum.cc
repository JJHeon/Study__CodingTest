#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using Song = struct Song {
    int id;
    string genre;
    int plays;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> hash;
    vector<Song> collection;

    for (auto itr = genres.begin(); itr != genres.end(); ++itr){
        auto plays_itr = plays.begin() + (itr - genres.begin());
        hash[*itr] += *plays_itr;
    }

        if (genres.size() != plays.size()) throw std::runtime_error("P");
    auto genres_itr = genres.cbegin();
    auto plays_itr = plays.cbegin();
    while (genres_itr != genres.cend() && plays_itr != plays.cend()) {
        const int idn = genres_itr - genres.cbegin();
        Song s{.id = idn, .genre = *genres_itr, .plays = *plays_itr};

        collection.push_back(std::move(s));

        genres_itr++;
        plays_itr++;
    }

    sort(collection.begin(), collection.end(), [&hash](const Song& t1, const Song& t2) -> bool {
        if (hash[t1.genre] > hash[t2.genre])
            return true;
        else if (hash[t1.genre] == hash[t2.genre]) {
            if (t1.plays > t2.plays)
                return true;
            else if (t1.plays == t2.plays) {
                if (t1.id > t2.id)
                    return false;
                else
                    return true;
            } else
                return false;
        } else
            return false;
    });

    string save_string = collection.begin()->genre;
    int count = 1;
    answer.push_back(collection.begin()->id);
    for (auto itr = collection.cbegin() + 1; itr != collection.cend(); ++itr) {
        if(count < 2 && save_string == itr->genre){
            count++;
            answer.push_back(itr->id);
        } else if(count == 2 && save_string == itr->genre){
            continue;
        }
        else{
            count = 1;
            save_string = itr->genre;
            answer.push_back(itr->id);
        }
    }

    return answer;
}