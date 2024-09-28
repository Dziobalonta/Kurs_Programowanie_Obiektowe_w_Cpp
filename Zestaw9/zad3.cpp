#include <iostream>
#include <memory>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::wstring;
using std::make_unique;
using std::wcout;


class Song
{
public:
  std::wstring artist;
  std::wstring title;
  Song(const std::wstring& _artist, const std::wstring& _title): artist(_artist), title(_title) {}
  ~Song() {}
};

unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title)
{
  // Implicit move operation into the variable that stores the result.
  return make_unique<Song>(artist, title);
}

void MakeSongs()
{
  // Create a new unique_ptr with a new object.
  auto song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");

  // Use the unique_ptr.
  vector<wstring> titles = { song->title };

  // Move raw pointer from one unique_ptr to another.
  unique_ptr<Song> song2 = std::move(song);

  // Obtain unique_ptr from function that returns by value.
  auto song3 = SongFactory(L"Michael Jackson", L"Beat It");
}

void SongVector()
{
    vector<unique_ptr<Song>> songs;
    
    // Create a few new unique_ptr<Song> instances
    // and add them to vector using implicit move semantics.
    songs.push_back(make_unique<Song>(L"B'z", L"Juice")); 
    songs.push_back(make_unique<Song>(L"Namie Amuro", L"Funky Town")); 
    songs.push_back(make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de")); 
    songs.push_back(make_unique<Song>(L"Ayumi Hamasaki", L"Poker Face"));

    // Pass by const reference when possible to avoid copying.
    for (const auto& song : songs) //const auto song : songs - error: use of deleted function 
    {
      wcout << L"Artist: " << song->artist << L"   Title: " << song->title << endl; 
    }    
}


int main()
{
  MakeSongs();
  SongVector();
  return 0;
}
