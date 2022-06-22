#include <string>
#include <vector>
#include <sstream>
#include <cstdint>

using namespace std;

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    int max_time_size = INT32_MIN;
    for (auto& info : musicinfos) {
        stringstream in(info);
        string out;
        vector<string> pieces;
        while (std::getline(in, out, ',')) pieces.push_back(out);

        int start = stoi(pieces[0].substr(0, 2)) * 60 + stoi(pieces[0].substr(3, 2));
        int end = stoi(pieces[1].substr(0, 2)) * 60 + stoi(pieces[1].substr(3, 2));
        int time_size = end - start;

        string song = "";
        int song_idx = 0;
        for (int i = 0; i < time_size; ++i) {
            if (song_idx + 1 < pieces[3].length() && pieces[3][song_idx + 1] == '#') {
                song += pieces[3].substr(song_idx, 2);
                song_idx += 2;
            } else {
                song += pieces[3].substr(song_idx, 1);
                song_idx += 1;
            }
            song_idx %= pieces[3].size();
        }

        int idx = 0;
        while ((idx = song.find(m, idx)) != string::npos) {
            if (song[idx + m.size()] != '#') {
                if (max_time_size < time_size) {
                    answer = pieces[2];
                    max_time_size = time_size;
                }
                break;
            }
            idx += 1;
        }
    }

    if (!answer.length()) answer = "(None)";
    return answer;
}