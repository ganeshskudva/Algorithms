// 535. Encode and Decode TinyURL
public class Codec {

        private Map<String, String> urlKeyMap, urlValMap;
        private char[] arr = {'a', 'b', 'c', 'd', 'e', 'f'};
        private int len;

        public Codec() {
            this.urlKeyMap = new HashMap<String, String>();
            len = arr.length;
            this.urlValMap = new HashMap<String, String>();
        }

        // Encodes a URL to a shortened URL.
        public String encode(String longUrl) {
            String ret = null;
            if (!this.urlKeyMap.containsKey(longUrl)) {
                ret = String.valueOf(arr[longUrl.length()%len]);
                this.urlKeyMap.put(longUrl, String.valueOf(arr[longUrl.length()%len]));
                this.urlValMap.put(String.valueOf(arr[longUrl.length()%len]), longUrl);
            }

            return ret;

        }

        // Decodes a shortened URL to its original URL.
        public String decode(String shortUrl) {
            String ret = null;

            if (this.urlValMap.containsKey(shortUrl)) {
                ret = this.urlValMap.get(shortUrl);
            }

            return ret;
        }
    }
