#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>


using namespace std;


/**
 * Data structure that represents a graph node. Each node has a value and an
 * adjacent list with references of all neighbors nodes
 */
struct node {
    const char* value;
    list<struct node*> adj_list;
};


/**
 * Basic graph class. We only implement methods used to create, print and
 * search in the graph. The purpose of this implementation is to explain
 * the Depth First Search algoritm using an adjacent list
 */
class Graph {

    private:
        /* Keep track of the root of the graph */
        struct node* root;

    public:
        Graph (struct node* root)
        {
            this->root = root;
        }

        /*
         * Method to add a new node to the graph. If no target node is given
         * we assume that we should add it from root node
         */
        struct node* add_node(struct node* new_node, struct node* target_node)
        {
            if(target_node == NULL) {
                target_node = this->root;
            }

            new_node->adj_list.push_back(target_node);
            target_node->adj_list.push_back(new_node);

            return new_node;
        }

        /*
         * Method for debugging purpose. Prints the adjacent list of a node
         */
        void print_adj_list (struct node* vertex) {

            cout << "[adjacent list] " << vertex->value << ": ";

            for(auto it: vertex->adj_list) {
                cout << it->value << " -> ";
            }

            cout << "NULL" << endl;
        }

        /*
         * Depth first search algorithm implemented using adjacent list.
         * The method searches for a given value starting from a root node.
         */
        struct node* depth_first_search(struct node* root,
                                          const char* value) {

            /* Memoization of the visited nodes */
            unordered_map<const char*, void*> visited;
            /* Stack used to store nodes that should be visited */
            stack<struct node*> node_stack;

            /* Adding root node in boths stack and visited */
            node_stack.push(root);
            visited[root->value] = NULL;

            /* While we have pending nodes to visit */
            while (!node_stack.empty()) {

                /* We respect the LIFO nature of the stack and get its top */
                struct node* current = node_stack.top();
                node_stack.pop();

                /* We the current node has the searched value we just return */
                if (current->value == value) {
                    return current;
                }

                /*
                 * If not, we iterate over the current node adjacent list to
                 * verify if they already been visited
                 */
                for (auto i: current->adj_list) {

                    /* If an node were not visited we add it to stack and mark
                     * as visited
                     */
                    if(visited.count(i->value) < 1) {
                        visited[i->value] = NULL;
                        node_stack.push(i);
                    }
                }
            }

            /* If not found the node with the value e return NULL reference */
            return NULL;
        }
};



int main (int argc, char* argv[])
{
    struct node root = {"Gustavo"};
    Graph* graph = new Graph(&root);

    struct node node0 = {"Fabiana"};
    graph->add_node(&node0, NULL);

    struct node node1 = {"Nina"};
    graph->add_node(&node1, &root);
    graph->add_node(&node1, &node0);

    struct node node2 = {"Junior"};
    graph->add_node(&node2, &root);
    graph->add_node(&node2, &node0);
    graph->add_node(&node2, &node1);

    struct node node3 = {"Gabriel"};
    graph->add_node(&node3, &root);
    graph->add_node(&node3, &node0);

    struct node node4 = {"Alice"};
    graph->add_node(&node4, &root);
    graph->add_node(&node4, &node0);

    graph->print_adj_list(&root);
    graph->print_adj_list(&node0);
    graph->print_adj_list(&node1);
    graph->print_adj_list(&node2);
    graph->print_adj_list(&node3);
    graph->print_adj_list(&node4);

    cout << "Search[" << node0.value << "] = ";
    struct node* found = graph->depth_first_search(&root, node0.value);
    if(found != NULL) {
        cout << "Found: " << found->value << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "Search[Junior] = ";
    found = graph->depth_first_search(&root, "Junior");
    if(found != NULL) {
        cout << "Found: " << found->value << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "Search[Gabriel] = ";
    found = graph->depth_first_search(&node1, "Gabriel");
    if(found != NULL) {
        cout << "Found: " << found->value << endl;
    } else {
        cout << "Not found" << endl;
    }

    cout << "Search[Fake] = ";
    found = graph->depth_first_search(&root, "Fake");
    if(found != NULL) {
        cout << "Found: " << found->value << endl;
    } else {
        cout << "Not found" << endl;
    }

    delete graph;

    return EXIT_SUCCESS;
}
