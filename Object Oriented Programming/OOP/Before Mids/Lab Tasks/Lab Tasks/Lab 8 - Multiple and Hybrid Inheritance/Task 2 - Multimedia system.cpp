#include <iostream>
using namespace std;

class AudioPlayer {
protected:
    string audioFormat;

public:
    AudioPlayer(string format) : audioFormat(format) {}

    void playAudio() {
        cout << "Playing Audio in " << audioFormat << " format..." << endl;
    }

    void stopAudio() {
        cout << "Stopping Audio..." << endl;
    }
};

class VideoPlayer {
protected:
    string videoFormat;

public:
    VideoPlayer(string format) : videoFormat(format) {}

    void playVideo() {
        cout << "Playing Video in " << videoFormat << " format..." << endl;
    }

    void stopVideo() {
        cout << "Stopping Video..." << endl;
    }
};

class MediaPlayer : public AudioPlayer, public VideoPlayer {
private:
    string quality;

public:
    MediaPlayer(string audioFmt, string videoFmt) : AudioPlayer(audioFmt), VideoPlayer(videoFmt) {}

    void setQuality(string q) {
        quality = q;
        cout << "Setting Playback Quality to " << quality << "..." << endl;
    }

    void displayQuality() {
        cout << "Current Playback Quality: " << quality << endl;
    }
};

int main() {
    MediaPlayer mp("MP3", "MP4");

    mp.playAudio();
    mp.stopAudio();
    mp.playVideo();
    mp.stopVideo();
    mp.setQuality("High");
    mp.displayQuality();

    return 0;
}

