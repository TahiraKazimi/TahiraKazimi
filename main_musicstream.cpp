#include <iostream>

#include "MusicStream.cpp"
using namespace std;
int main() {
    MusicStream ms;

    ms.print();

    ms.addProfile("john@doe.com", "john_doe", free_of_charge);
    ms.addProfile("kazimi.thk@gmail.com","daisy",premium);

    ms.addArtist("Kenshi");

    ms.addAlbum("Please Please Me", 1);
    ms.addAlbum("A Hard Day's Night", 1);
    ms.addSong("Peace Sign", 175, 1);
    ms.addSong("Shinigami", 116, 1);
    ms.addSong("Paprika", 155, 2);
    ms.addSong("You Can't Do That", 155, 2);
    ms.followProfile("john@doe.com","kazimi.thk@gmail.com");
    ms.followProfile("kazimi.thk@gmail.com","john@doe.com");
    //ms.unfollowProfile("kazimi.thk@gmail.com","john@doe.com");
    ms.createPlaylist("kazimi.thk@gmail.com","Kenshi Yonezu");
    ms.createPlaylist("john@doe.com","classics");
    ms.createPlaylist("kazimi.thk@gmail.com","Yoasobi");
    ms.addSongToPlaylist("kazimi.thk@gmail.com",5,1);
    ms.addSongToPlaylist("kazimi.thk@gmail.com",4,1);
    ms.addSongToPlaylist("kazimi.thk@gmail.com",2,1);
    ms.addSongToPlaylist("john@doe.com",3,2);
     ms.unsubscribePremium("kazimi.thk@gmail.com");
    //ms.deleteSongFromPlaylist("kazimi.thk@gmail.com",4,1);
    Playlist * playlist = ms.getPlaylist("kazimi.thk@gmail.com",1);
    LinkedList<Song*> songs = ms.playPlaylist("kazimi.thk@gmail.com",playlist);
    Node<Song*>* one_song = songs.getNodeAtIndex(0);
    cout<<*(one_song->data)<<endl;
    one_song = songs.getNodeAtIndex(1);
    cout<<*(one_song->data)<<endl;
    one_song = songs.getNodeAtIndex(2);
    cout<<*(one_song->data)<<endl;
    ms.sharePlaylist("kazimi.thk@gmail.com",1);
    ms.shufflePlaylist("kazimi.thk@gmail.com",1,2);
    ms.deleteProfile("john@doe.com");
    ms.print();


    return 0;
}
