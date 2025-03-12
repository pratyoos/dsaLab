#include <stdio.h>
#include <stdlib.h>

struct BST {
    int data;
    struct BST *left;
    struct BST *right;
    struct BST *parent;
};
typedef struct BST Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
        root->left->parent = root;
    } else if (data > root->data) {
        root->right = insert(root->right, data);
        root->right->parent = root;
    }

    return root;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }

    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

Node* findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
        if (root->left) root->left->parent = root;
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
        if (root->right) root->right->parent = root;
    } else {

        if (root->left == NULL) {
            Node* temp = root->right;
            if (temp) temp->parent = root->parent;
            free(root);
            return temp;
        } 
        
        else if (root->right == NULL) {
            Node* temp = root->left;
            if (temp) temp->parent = root->parent;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
        if (root->right) root->right->parent = root;
    }
    return root;
}

int main() {
    Node* root = NULL;
    int choice, data;
    Node* searchResult;

    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder\n");
        printf("5. Preorder\n");
        printf("6. Postorder\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("%d inserted.\n", data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                printf("%d deleted.\n", data);
                break;

            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                searchResult = search(root, data);
                if (searchResult != NULL) {
                    printf("Node with data %d found.\n", data);
                } else {
                    printf("Node with data %d not found.\n", data);
                }
                break;

            case 4:
                printf("In-order traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Pre-order traversal: ");
                preOrderTraversal(root);
                printf("\n");
                break;

            case 6:
                printf("Post-order traversal: ");
                postOrderTraversal(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}