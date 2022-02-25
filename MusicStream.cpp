#include "MusicStream.h"
#include <iostream>

void MusicStream::addProfile(const std::string &email, const std::string &username, SubscriptionPlan plan) {
    /* TODO */
    Profile* new_prof = new Profile(email,username,plan);
    profiles.insertAtTheEnd(*new_prof);
    delete new_prof;
}

void MusicStream::deleteProfile(const std::string &email) {
    Node<Profile> * current = profiles.getFirstNode();
    LinkedList<Profile*> following, followers;
    while((current->data).getEmail()!=email){
        current = current->next;
    }
  following = current->data.getFollowings(); int i = 0;
  Node<Profile*>* node_following = following.getFirstNode();
  while(i<following.getSize()){
      current->data.unfollowProfile(node_following->data);
      node_following = node_following->next;
      i++;
  }
  followers = current->data.getFollowers(); int j = 0;
  Node<Profile*> * one_follower = followers.getFirstNode();
  while(j<followers.getSize()){
      one_follower->data->unfollowProfile(&current->data);
      one_follower = one_follower->next;
      j++;
  }
    (current->data).getPlaylists().removeAllNodes();
    (current->data).getFollowers().removeAllNodes();
    (current->data).getFollowings().removeAllNodes();
    profiles.removeNode(current);

}

void MusicStream::addArtist(const std::string &artistName) {

    Artist* new_artist = new Artist(artistName);
    artists.insertAtTheEnd(*new_artist);
    delete new_artist;
}

void MusicStream::addAlbum(const std::string &albumName, int artistId) {
    /* TODO */
    Album *new_album = new Album(albumName);
    albums.insertAtTheEnd(*new_album);
    Node<Artist> * current_artist = artists.getFirstNode();
    while(current_artist->data.getArtistId()!=artistId){
        current_artist = current_artist->next;
    }
    Album *new_album2 = &(albums.getLastNode()->data); 
    current_artist->data.addAlbum(new_album2);
    delete new_album;
}

void MusicStream::addSong(const std::string &songName, int songDuration, int albumId) {
    /* TODO */
    Song* new_song = new Song(songName,songDuration);
    songs.insertAtTheEnd((*new_song));
    Node<Album> * current_album = albums.getFirstNode();
    while(current_album->data.getAlbumId()!=albumId){
        current_album = current_album->next;
    }
    Song* new_song2 = &(songs.getLastNode()->data);
    current_album->data.addSong(new_song2);
    delete new_song;

}

void MusicStream::followProfile(const std::string &email1, const std::string &email2) {
    /* TODO */
    Node<Profile>* follower = profiles.getFirstNode();
    Node<Profile>* following = profiles.getFirstNode();
    while(follower->data.getEmail()!=email1){
        follower = follower->next;
    }
    while(following->data.getEmail()!=email2){
        following = following->next;
    }
    follower->data.followProfile(&following->data);
}

void MusicStream::unfollowProfile(const std::string &email1, const std::string &email2) {
    /* TODO */
     Node<Profile>* follower = profiles.getFirstNode();
    Node<Profile>* following = profiles.getFirstNode();
    while(follower->data.getEmail()!=email1){
        follower = follower->next;
    }
    while(following->data.getEmail()!=email2){
        following = following->next;
    }
    follower->data.unfollowProfile(&(following->data));

}

void MusicStream::createPlaylist(const std::string &email, const std::string &playlistName) {
    /* TODO */
    Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    user->data.createPlaylist(playlistName);
}

void MusicStream::deletePlaylist(const std::string &email, int playlistId) {
    /* TODO */
    Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    user->data.deletePlaylist(playlistId);
}

void MusicStream::addSongToPlaylist(const std::string &email, int songId, int playlistId) {
    /* TODO */
    Node<Song>* song_node = songs.getFirstNode();
    while(song_node->data.getSongId()!=songId){
        song_node = song_node->next;
    }
    Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    Song * song_p = &(song_node->data);
    (user->data).addSongToPlaylist(song_p,playlistId);
}

void MusicStream::deleteSongFromPlaylist(const std::string &email, int songId, int playlistId) {
    /* TODO */
    Node<Song>* song_node = songs.getFirstNode();
    while(song_node->data.getSongId()!=songId){
        song_node = song_node->next;
    }
    Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    (user->data).deleteSongFromPlaylist(&(song_node->data),playlistId);

}

LinkedList<Song *> MusicStream::playPlaylist(const std::string &email, Playlist *playlist) {
    /* TODO */
    Node<Profile>* user = profiles.getFirstNode();
    LinkedList<Song*> song_list = playlist->getSongs();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    if(user->data.getPlan()==premium){
        return song_list;
    }
    else{
        song_list.insertAsEveryKthNode(&(Song::ADVERTISEMENT_SONG),2);
        return song_list; 
    }
}

Playlist *MusicStream::getPlaylist(const std::string &email, int playlistId) {
    /* TODO */
    Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    Playlist * wantedPlaylist = user->data.getPlaylist(playlistId);
    return wantedPlaylist;
}

LinkedList<Playlist *> MusicStream::getSharedPlaylists(const std::string &email) {
    /* TODO */
    Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    LinkedList<Profile *> following = user->data.getFollowings();
    LinkedList<Playlist*> sharedPlaylist,totalSharedPlaylist;
    int i = 0; Node<Profile *> * one_following = following.getFirstNode();
    while(i<following.getSize()){
        sharedPlaylist = (one_following->data)->getSharedPlaylists();
        int j = 0;
        while( j<sharedPlaylist.getSize()){
            totalSharedPlaylist.insertAtTheEnd(sharedPlaylist.getNodeAtIndex(j)->data);
            j++;
        }
        one_following = one_following->next;
        i++;
    }
    return totalSharedPlaylist;
}

void MusicStream::shufflePlaylist(const std::string &email, int playlistId, int seed) {
    /* TODO */
    Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    user->data.shufflePlaylist(playlistId,seed);

}

void MusicStream::sharePlaylist(const std::string &email, int playlistId) {
    /* TODO */
    Playlist* get_playlist = getPlaylist(email,playlistId);
    get_playlist->setShared(true);
}

void MusicStream::unsharePlaylist(const std::string &email, int playlistId) {
    /* TODO */
    Playlist* get_playlist = getPlaylist(email,playlistId);
    get_playlist->setShared(false);
}

void MusicStream::subscribePremium(const std::string &email) {
    /* TODO */
    Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    user->data.setPlan(premium);
}

void MusicStream::unsubscribePremium(const std::string &email) {
    /* TODO */
     Node<Profile>* user = profiles.getFirstNode();
    while(user->data.getEmail()!=email){
        user = user->next;
    }
    user->data.setPlan(free_of_charge);
}

void MusicStream::print() const {
    std::cout << "# Printing the music stream ..." << std::endl;

    std::cout << "# Number of profiles is " << this->profiles.getSize() << ":" << std::endl;
    this->profiles.print();

    std::cout << "# Number of artists is " << this->artists.getSize() << ":" << std::endl;
    this->artists.print();

    std::cout << "# Number of albums is " << this->albums.getSize() << ":" << std::endl;
    this->albums.print();

    std::cout << "# Number of songs is " << this->songs.getSize() << ":" << std::endl;
    this->songs.print();

    std::cout << "# Printing is done." << std::endl;
}
