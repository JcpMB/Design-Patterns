#include<iostream>
#include<vector>

class YoutubeInterface {
    public:
        YoutubeInterface(){};
        virtual void listVideos() = 0;
        virtual std::string getVideoInfo( int id ) = 0;
        virtual void download() = 0;
};

class YoutubeDownloader : public YoutubeInterface {
    private:
        std::vector<std::string> videos;
    public:
        YoutubeDownloader(){};
        void listVideos() override {
            if( videos.size() != 0 ){
                for( const std::string& vid : videos )
                    std::cout << "video:" << vid << std::endl;
            }else{
                std::cout << "[Downloader] No element to show" << std::endl;
            }
        }
        std::string getVideoInfo(int id) override {
            if( videos.size() != 0 && id < videos.size() )
                return videos[id];
            else
                return "";
        }
        void download() override {
            videos.push_back("video-1");
            videos.push_back("video-2");
            videos.push_back("video-3");
            videos.push_back("video-4");
            videos.push_back("video-5");
            videos.push_back("video-6");
            videos.push_back("video-7");
        }
};

class YoutubeProxy : public YoutubeInterface {
    private:
        YoutubeDownloader * downloader;
    public:
        YoutubeProxy( YoutubeDownloader * downloader ) : downloader( downloader ) {}
        void listVideos() override {
            std::cout << "[Proxy] Doing something before listing" << std::endl;
            downloader->listVideos();
        }
        std::string getVideoInfo(int id ) override {
            std::cout << "[Proxy] Getting the vid" << std::endl;
            return downloader->getVideoInfo(id);
        }
        void download() override {
            std::cout << "[Proxy] downloading ..." << std::endl;
            downloader->download();
        }
};

/* 
    This patter is way very useful, it has many applications as caching proxy, logging proxy or as a simpler handler for services
    the only takeaway to consider here is to make method for passing the service to the proxy, instead of using the constructor
    Not many downsides, beside the increase of complexity. 

    it could be nice also to implement a caching mechanism, if I download the same thing over and over 
    I can optmize by storing the vid and then fetching it if it has already been downloaded.
 */

int main( int argc, char * argv[] ){

    YoutubeProxy * downloader = new YoutubeProxy( new YoutubeDownloader() );

    downloader->download();
    downloader->listVideos();   

    std::cout << "[Client] video:" << downloader->getVideoInfo(2) << std::endl;
    return 0;
}