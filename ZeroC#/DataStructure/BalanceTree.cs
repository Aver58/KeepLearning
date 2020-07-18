using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructure
{
    class BalanceTree
    {
        #region 4.2 平衡二叉树
        /*
            AVL = 每层树高度*层结点个数之和的平均值
            平衡因子 = BF（T）= h(L) - h(R)
            平衡二叉树（AVL树）：
                指空树，或者任一结点左右子树高度差小于1
                |BF（T）| <= 1
         
                给定结点数为 n的AVL树的最大高度为O(log2n)！

            一、平衡二叉树的调整
                ①不平衡的结点在发现者右子树的右边，因而叫 RR 插入，需要RR 旋转（右单旋）
                ②不平衡的结点在发现者左子树的左边，因而叫 LL 插入，需要LL 旋转（左单旋）
                ③不平衡的结点在发现者左子树的右边，因而叫 LR 插入，需要LR 旋转                ④不平衡的结点在发现者右子树的左边，因而叫 RL 插入，需要RL 旋转                注意：有时候插入元素即便
                    不需要调整结构，也可能需要重新计算
                    一些平衡因子。
         */
        #endregion

        public Tree tree { get; private set; }
        private int m_size = 0;

        public BalanceTree(int i)
        {
            tree = new Tree(i);
            m_size++;
        }
        /// <summary>
        /// 将 X 插入 AVL 树 T 中，并且返回调整后的 AVL 树
        /// </summary>
        /// <param name="tree"></param>
        /// <param name="i"></param>
        public void Insert(TreeNode tree,int i)
        {
            /* 若插入空树，则新建包含一个结点的树 */
            if (tree == null)
            {
                var newTree = new Tree(i);
                return;
            }
            //var tempNode = tree.headNode;
            /* 插入左子树 */
            if (i < tempNode.data)
            {
                tempNode.left = Insert(tempNode.left,i);
                if (true)
                {

                }
            }
            else
            {
                    
            }
        }

        //else if (X<T->Data) { /* 插入 T 的左子树 */
        //T->Left = AVL_Insertion(X, T->Left);
        // if (GetHeight(T->Left) - GetHeight(T->Right) == 2 )
        ///* 需要左旋 */
        // if (X<T->Left->Data)
        // T = SingleLeftRotation(T); /* 左单旋 */
        // else
        // T = DoubleLeftRightRotation(T); /* 左-右双旋 */
        //} /* else if (插入左子树) 结束 */

        //else if (X > T->Data) { /* 插入 T 的右子树 */
        //T->Right = AVL_Insertion(X, T->Right);
        // if (GetHeight(T->Left) - GetHeight(T->Right) == -2 )
        ///* 需要右旋 */
        // if (X > T->Right->Data)
        // T = SingleRightRotation(T); /* 右单旋 */
        // else
        // T = DoubleRightLeftRotation(T); /* 右-左双旋 */
        //} /* else if (插入右子树) 结束 */
        // /* else X == T->Data，无须插入 */
        //T->Height = Max(GetHeight(T->Left),GetHeight(T->Right))+1;
        ///*更新树高*/
        //return T;
        //}


        
        public TreeNode SingleLeftRotation(TreeNode A)
        {
            /* 注意：A 必须有一个左子结点 B */
            /* 将 A 与 B 左单旋，更新 A 与 B 的高度，返回新的根结点 B */
            /*
                A                B
               /    左单旋      / \
              B    ========>   C   A
             /
            C
             */
            //判断是在这里判断还是在外面判断
            var B = A.left;
            A.left = B.right;
            B.right = A;
            //A.height = Math.Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
            //B.height = Math.Max(GetHeight(B->Left), A->Height) + 1;
            return B;
        }


        //AVLTree DoubleLeftRightRotation(AVLTree A)
        //{ /* 注意：A 必须有一个左子结点 B，且 B 必须有一个右子结点 C */
        //  /* 将 A、B 与 C 做如图 4.38 所示的两次单旋，返回新的根结点 C */

        //    A->Left = SingleRightRotation(A->Left); /*将 B 与 C 做右单旋，C 被返回*/
        //    return SingleLeftRotation(A); /*将 A 与 C 做左单旋，C 被返回*/
        //}

    }
}
