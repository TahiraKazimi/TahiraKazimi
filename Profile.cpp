#include "Profile.h"

Profile::Profile(const std::string &email, const std::string &username, SubscriptionPlan plan) {
    this->email = email;
    this->username = username;
    this->plan = plan;
}

const std::string &Profile::getUsername() const {
    return this->username;
}

const std::string &Profile::getEmail() const {
    return this->email;
}

SubscriptionPlan Profile::getPlan() const {
    return this->plan;
}

LinkedList<Playlist> &Profile::getPlaylists() {
    return this->playlists;
}

LinkedList<Profile *> &Profile::getFollowings() {
    return this->following;
}

LinkedList<Profile *> &Profile::getFollowers() {
    return this->followers;
}

void Profile::setPlan(SubscriptionPlan plan) {
    this->plan = plan;
}

void Profile::followProfile(Profile *profile) {
    /* TODO */
    following.insertAtTheEnd(profile);
    profile->getFollowers().insertAtTheEnd(this);
}

void Profile::unfollowProfile(Profile *profile) {
    /* TODO */
    following.removeNode(profile);
    profile->getFollowers().removeNode(this);
}

void Profile::createPlaylist(const std::string &playlistName) {
    /* TODO */
    Playlist new_playlist(playlistName);
    playlists.insertAtTheEnd(new_playlist);
}

void Profile::deletePlaylist(int playlistId) {
    /* TODO */
    Node<Playlist>* current = playlists.getFirstNode();
    while((current->data).getPlaylistId()!=playlistId){
        current = current->next;
    }
    playlists.removeNode(current);
}

void Profile::addSongToPlaylist(Song *song, int playlistId) {
    /* TODO */
    Node<Playlist>* current = playlists.getFirstNode();
    while((current->data).getPlaylistId()!=playlistId){
        current = current->next;
    }
    (current->data).addSong(song);
}

void Profile::deleteSongFromPlaylist(Song *song, int playlistId) {
    /* TODO */
    Node<Playlist>* current = playlists.getFirstNode();
    while((current->data).getPlaylistId()!=playlistId){
        current = current->next;
    }
    (current->data).dropSong(song);
}

Playlist *Profile::getPlaylist(int playlistId) {
    /* TODO */
    Playlist * playlist_p ;
    Node<Playlist>* current = playlists.getFirstNode();
    while((current->data).getPlaylistId()!=playlistId){
        current = current->next;
    }
    playlist_p = &(current->data);
    return playlist_p;
}

LinkedList<Playlist *> Profile::getSharedPlaylists() {
    /* TODO */
    LinkedList<Playlist *> sharedPlaylists;
    Playlist* p;
    Node<Playlist> *current = playlists.getFirstNode();
    int i=0; int size = playlists.getSize();
    while(i<size){
        if((current->data).isShared()){
            p =&(current->data);
            sharedPlaylists.insertAtTheEnd(p);
            current = current->next;
        }
        i++;
    }
    return sharedPlaylists;
}

void Profile::shufflePlaylist(int playlistId, int seed) {
    /* TODO */
    Playlist * p; p = getPlaylist(playlistId);
    p->shuffle(seed);

}

void Profile::sharePlaylist(int playlistId) {
    /* TODO */
    Playlist *p; p = getPlaylist(playlistId);
    p->setShared(true);
}

void Profile::unsharePlaylist(int playlistId) {
    /* TODO */
    Playlist* p; p= getPlaylist(playlistId);
    p->setShared(false);
}


bool Profile::operator==(const Profile &rhs) const {
    return this->email == rhs.email && this->username == rhs.username && this->plan == rhs.plan;
}

bool Profile::operator!=(const Profile &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Profile &profile) {
    os << "email: " << profile.email << " |";
    os << " username: " << profile.username << " |";
    if (profile.plan == free_of_charge) {
        os << " plan: " << "free_of_charge" << " |";
    } else if (profile.plan == premium) {
        os << " plan: " << "premium" << " |";
    } else {
        os << " plan: " << "undefined" << " |";
    }

    os << " playlists: [";
    Node<Playlist> *firstPlaylistNode = profile.playlists.getFirstNode();
    Node<Playlist> *playlistNode = firstPlaylistNode;
    if (playlistNode) {
        do {
            os << playlistNode->data;
            if (playlistNode->next != firstPlaylistNode) os << ", ";
            playlistNode = playlistNode->next;
        } while (playlistNode != firstPlaylistNode);
    }
    os << "] |";
    os << " following: [";
    Node<Profile *> *firstProfileNode = profile.following.getFirstNode();
    Node<Profile *> *profileNode = firstProfileNode;
    if (profileNode) {
        do {
            os << profileNode->data->getEmail();
            if (profileNode->next != firstProfileNode) os << ", ";
            profileNode = profileNode->next;
        } while (profileNode != firstProfileNode);
    }
    os << "] |";
    os << " followers: [";
    firstProfileNode = profile.followers.getFirstNode();
    profileNode = firstProfileNode;
    if (profileNode) {
        do {
            os << profileNode->data->getEmail();
            if (profileNode->next != firstProfileNode) os << ", ";
            profileNode = profileNode->next;
        } while (profileNode != firstProfileNode);
    }
    os << "]";

    return os;
}
