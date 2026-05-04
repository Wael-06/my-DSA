struct Trienode
{
    unordered_map<char, unique_ptr<Trienode>> children;
    bool terminal = false;
};

class PrefixTree {
private:
unique_ptr<Trienode> root;
public:
    PrefixTree() {
        root = make_unique<Trienode>();
    }
    
    void insert(string word) {
        Trienode* tmp = root.get();
    

        for(const char c: word ){
            if(tmp->children.find(c) == tmp->children.end()){
                tmp->children[c] = make_unique<Trienode>();
            }
            tmp = tmp->children[c].get();
        }

        tmp->terminal = true;

    }
    
    bool search(string word) {
        Trienode* tmp = root.get();

        for(const char c: word){
            if(tmp->children.find(c) == tmp->children.end()){
                return false;
            }

            tmp = tmp->children[c].get();
        }

        return tmp->terminal;
        
    }
    
    bool startsWith(string prefix) {

        Trienode* tmp = root.get();

        for(const char c: prefix){
            if(tmp->children.find(c) == tmp->children.end()){
                return false;
            }

            tmp = tmp->children[c].get();
        }

        return true;
        
    }
};