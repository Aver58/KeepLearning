using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructure
{
    #region 3.0 基础知识
    /*
    * 树的一些基本术语

         1. 结点的度（Degree）：结点的子树个数
         2. 树的度：树的所有结点中最大的度数
         3. 叶结点（Leaf）：度为0的结点
         4. 父结点（Parent）：有子树的结点是其子树
             的根结点的父结点
         5. 子结点（Child）：若A结点是B结点的父结
             点，则称B结点是A结点的子结点；子结点也
             称孩子结点。
         6. 兄弟结点（Sibling）：具有同一父结点的各
             结点彼此是兄弟结点。
         7. 路径和路径长度：从结点n1到nk的路径为一
             个结点序列n1 , n2
             ,… , nk
             , ni是 ni+1的父结
             点。路径所包含边的个数为路径的长度。
         9. 祖先结点(Ancestor)：沿树根到某一结点路
             径上的所有结点都是这个结点的祖先结点。
         10. 子孙结点(Descendant)：某一结点的子树
             中的所有结点是这个结点的子孙。
         11. 结点的层次（Level）：规定根结点在1层，
             其它任一结点的层数是其父结点的层数加1。
         12. 树的深度（Depth）：树中所有结点中的最
             大层次是这棵树的深度
     */

    /*
     * 小技巧
         1. 判定树上每个结点需要的查找次数刚好为该结点所在的层数; 
         2. 查找成功时查找次数不会超过判定树的深度
         3. n个结点的判定树的深度为[log2n]+1.
     
         4. 子树是不相交的；
               5. 除了根结点外，每个结点有且仅有一个父结点；
               6. 一棵N个结点的树有N-1条边。
     */
    #endregion

    #region 3.1树的表现
    //①儿子-兄弟表示
    public class Son_SiblingNode
    {
        // 二叉树
        Son_SiblingNode First_Child;
        Son_SiblingNode Next_Sibling;
    }
    #endregion

    #region 3.2二叉树的存储结构
        //1. 顺序存储
        //    ①完全二叉树：按从上至下、从左到右顺序存储
        //    ①一般二叉树：但会造成空间浪费
        //2. 链式存储
        public class TreeNode
        {
            public int data;
            public TreeNode left;
            public TreeNode right;
            //写着写着就变成了三叉树
            public TreeNode parent;
            //写平衡树加上的
            public int height;


        public TreeNode() { }

            public TreeNode(int value)
            {
                data = value;
            }
            public void DisplayData()
            {
                Console.Write(data + " ");
            }
        }
    #endregion

    public interface ITree
    {
        int GetLength();
        int GetHeight(TreeNode tree);
        bool IsEmpty();
        void Clear();
        TreeNode Find(int i);
        TreeNode FindMax(TreeNode tree);
        TreeNode FindMin(TreeNode tree);
        void Delete(Tree tree, int i);
        void Insert(Tree tree, int item);
        void Reverse();
    }

    public class Tree: ITree
    {
        private int m_Size = 0;

        public TreeNode headNode { get; private set; }
        public Tree() { }

        public Tree(int data)
        {
            headNode = new TreeNode(data);
            headNode.left = null;
            headNode.right = null;
            headNode.parent = null;
            headNode.height = 0;
            m_Size++;
        }

        public int GetLength()
        {
            return m_Size;
        }

        /// <summary>
        /// 求树的高度
        /// </summary>
        /// <param name="tree"></param>
        /// <returns></returns>
        public int GetHeight(TreeNode tree)
        {
            int HeightL = 0, HeightR = 0;
            var tempNode = tree;
            while (tempNode != null)
            {
                tempNode = tempNode.left;
                HeightL += 1;
            }
            tempNode = headNode;
            if (tempNode!=null)
            {
                tempNode = tempNode.left;
                HeightR += 1;
            }
            int maxHeight = Math.Max(HeightL, HeightR);
            Console.WriteLine("HeightL:" + HeightL + "HeightR:" + HeightR);
            return (maxHeight + 1);
        }
        /// <summary>
        /// 判断是否为空
        /// </summary>
        /// <returns></returns>
        public bool IsEmpty()
        {
            return headNode == null;
        }

        #region 增删改查
        /// <summary>
        /// 清空树
        /// </summary>
        public void Clear()
        {
            headNode = new TreeNode();
            headNode.left = null;
            headNode.right = null;
            headNode.parent = null;
            m_Size = 0;
        }

        /// <summary>
        /// 查找并返回最大结点
        /// </summary>
        /// <param name="tree"></param>
        /// <returns></returns>
        public TreeNode FindMax(TreeNode tree)
        {
            var tempNode = tree;
            while (tempNode != null)
            {
                if (tempNode.right == null)
                {
                    break;
                }
                tempNode = tempNode.right;
            }
            return tempNode;
        }

        /// <summary>
        /// 查找并返回最小结点
        /// </summary>
        /// <param name="tree"></param>
        /// <returns></returns>
        public TreeNode FindMin(TreeNode tree)
        {
            var tempNode = tree;
            while (tempNode != null)
            {
                if (tempNode.left == null)
                {
                    break;
                }
                tempNode = tempNode.left;
            }
            return tempNode;
        }

        /// <summary>
        /// 查找并返回指定结点，没找到返回null
        /// </summary>
        /// <param name="i"></param>
        /// <returns></returns>
        public TreeNode Find(int i)
        {
            TreeNode tempNode = new TreeNode();
            tempNode = headNode;
            while (tempNode != null)
            {
                if (i < tempNode.data)
                {
                    tempNode = tempNode.left;
                }
                else if (i > tempNode.data)
                {
                    tempNode = tempNode.right;
                }
                else
                {
                    return tempNode;
                }
            }
            return null;
        }

        /// <summary>
        /// 二叉树的删除是最麻烦的，需要考虑四种情况：
        ///   被删节点是叶子节点
        ///   被删节点有左孩子没右孩子
        ///   被删节点有右孩子没左孩子
        ///   被删节点有两个孩子
        /// </summary>
        /// <param name="tree"></param>
        /// <param name="i"></param>
        public void Delete(Tree tree, int i)
        {
            TreeNode tempNode = Find(i);
            //If the value doesn't exist
            if (tempNode.data != i)
            {
                return;
            }

            if (tempNode == tree.headNode)
            {
                tree = null;
            }

            //No Children
            if (tempNode.left == null && tempNode.right == null)
            {
                if (tempNode.parent.data < tempNode.data)
                {
                    tempNode.parent.right = null;
                }
                else
                {
                    // 完全二叉树不存在相等的情况？
                    tempNode.parent.left = null;
                }
            }

            //Two Children
            else if (tempNode.left != null && tempNode.right != null)
            {
                //用另一结点替代被删除结点： 
                //右子树的最小元素 
                //或者  
                //左子树的最大元素
                var maxNode = FindMax(tempNode.left);
                //maxNode.parent.right = null;
                //先判断是父子树的什么结点
                if (tempNode.data < tempNode.parent.data)
                {
                    tempNode.parent.left = maxNode;
                }
                else
                {
                    tempNode.parent.right = maxNode;
                }
                maxNode.parent = tempNode.parent;
                maxNode.right = tempNode.right;
            }

            //One Children
            else
            {
                //If it has a right child
                if (tempNode.right != null)
                {
                    //if it is the left node
                    if (tempNode.data < tempNode.parent.data)
                    {
                        tempNode.parent.left = tempNode.right;
                    }
                    else
                    {
                        tempNode.parent.right = tempNode.right;
                    }
                }
                //If it has a left child
                else
                {
                    if (tempNode.data < tempNode.parent.data)
                    {
                        tempNode.parent.left = tempNode.right;
                    }
                    else
                    {
                        tempNode.parent.right = tempNode.right;
                    }
                }
            }
            m_Size--;
        }

        /// <summary>
        /// 插入结点
        /// </summary>
        /// <param name="tree"></param>
        /// <param name="item"></param>
        public void Insert(Tree tree, int item)
        {
            TreeNode newNode = new TreeNode(item);
            if (headNode == null)
            {
                headNode = newNode;
                return;
            }
            var tempNode = tree.headNode;
            while (tempNode != null)
            {
                if (newNode.data < tempNode.data)
                {
                    if (tempNode.left == null)
                    {
                        tempNode.left = newNode;
                        newNode.parent = tempNode;
                        break;
                    }
                    tempNode = tempNode.left;
                }
                else
                {
                    if (tempNode.right == null)
                    {
                        tempNode.right = newNode;
                        newNode.parent = tempNode;
                        break;
                    }
                    tempNode = tempNode.right;
                }
            }
            m_Size++;
        }

        public void Reverse()
        {
            throw new NotImplementedException();
        }
        #endregion

        #region 3.3 三叉树的遍历
        //以ABCDEFGHI为例子

        // (1)先序遍历:
        // ①先访问根节点
        // ②先序遍历左子树
        // ③先序遍历右子树

        // 先序遍历递归版(先中间，后两边)
        public void PreOrder(TreeNode tree)
        {
            if (tree == null)
            {
                return;
            }
            tree.DisplayData();
            PreOrder(tree.left);
            PreOrder(tree.right);
        }

        // (2)中序遍历(左中右)
        public void InOrder(TreeNode tree)
        {
            if (tree == null)
            {
                return;
            }
            InOrder(tree.left);
            tree.DisplayData();
            InOrder(tree.right);
        }

        // (3)后序遍历（先左右，后中间）
        public void PostOrder(TreeNode tree)
        {
            if (tree == null)
            {
                return;
            }
            PostOrder(tree.left);
            PostOrder(tree.right);
            tree.DisplayData();
        }

        // (4)层序遍历
        //从根节点开始入队，开始循环：（结点出队、访问该结点、其左右儿子入队）
        public void LevelOrder(TreeNode tree)
        {
            if (tree == null)
            {
                return;
            }
            //根节点开始入队
            Queue<TreeNode> queue = new Queue<TreeNode>();
            queue.Enqueue(tree);

            TreeNode tempNode;
            while (queue.Any())
            {
                // 结点出队
                tempNode = queue.Dequeue();
                tempNode.DisplayData();
                if (tempNode.left != null)
                {
                    queue.Enqueue(tempNode.left);
                }
                if (tempNode.right != null)
                {
                    queue.Enqueue(tempNode.right);
                }
            }
        }
        // 先序遍历非递归版
        public void PreOrderNoRecursion(TreeNode tree)
        {
            if (tree == null)
            {
                return;
            }
            //建个空栈
            Stack<TreeNode> stack = new Stack<TreeNode>();
            var node = tree;
            while (node != null || stack.Any())
            {
                if (node != null)
                {
                    /*一直向左并将沿途结点压入堆栈*/
                    stack.Push(node);
                    node.DisplayData();
                    node = node.left;
                }
                else
                {
                    var item = stack.Pop();/*结点弹出堆栈*/
                    node = item.right;/*转向右子树*/
                }
            }
        }

        //中序
        public void InOrderNoRecursion(TreeNode tree)
        {
            if (tree == null)
            {
                return;
            }
            Stack<TreeNode> stack = new Stack<TreeNode>();
            var node = tree;
            while (node != null || stack.Any())
            {
                if (node != null)
                {
                    /*一直向左并将沿途结点压入堆栈*/
                    stack.Push(node);
                    node = node.left;
                }
                else
                {
                    var item = stack.Pop();/*结点弹出堆栈*/
                    item.DisplayData();
                    node = item.right;/*转向右子树*/
                }
            }
        }

        //后序
        public void PostOrderNoRecursion(TreeNode tree)
        {
            if (tree == null)
            {
                return;
            }
            //建个空栈
            Stack<TreeNode> stack = new Stack<TreeNode>();
            HashSet<TreeNode> visited = new HashSet<TreeNode>();
            var node = tree;
            while (node != null || stack.Any())
            {
                if (node != null)
                {
                    /*一直向左并将沿途结点压入堆栈*/
                    stack.Push(node);
                    node = node.left;
                }
                else
                {
                    var item = stack.Peek();
                    // 右结点不为空并且还没有访问过
                    if (item.right != null && !visited.Contains(item.right))
                    {
                        /*转向右子树*/
                        node = item.right;
                    }
                    else
                    {
                        //如果访问过就/*结点弹出堆栈*/
                        item.DisplayData();
                        visited.Add(item);
                        stack.Pop();
                    }
                    //var item = stack.Pop();
                    //node = item.right;
                }
            }
        }
        #endregion

    }
    class Program
    {
        static void Mains(string[] args)
        {
            Tree tree = new Tree(5);
            tree.Insert(tree,2);
            tree.Insert(tree,3);
            tree.Insert(tree,4);
            tree.Insert(tree,1);
            tree.Insert(tree,6);
            tree.Insert(tree,7);
            tree.Insert(tree,8);
            tree.Insert(tree,9);
            //tree.Delete(tree, 2);

            Console.WriteLine("前序遍历");
            tree.PreOrder(tree.headNode);
            Console.WriteLine();
            tree.PreOrderNoRecursion(tree.headNode);
            Console.WriteLine();
            Console.WriteLine("中序遍历");
            tree.InOrder(tree.headNode);
            Console.WriteLine();
            tree.InOrderNoRecursion(tree.headNode);
            Console.WriteLine();
            Console.WriteLine("后序遍历");
            tree.PostOrder(tree.headNode);
            Console.WriteLine();
            tree.PostOrderNoRecursion(tree.headNode);
            Console.WriteLine();
            Console.WriteLine("层序遍历");
            tree.LevelOrder(tree.headNode);

            //tree.Find(5).DisplayData();
            Console.WriteLine();
            Console.WriteLine("GetLength：" + tree.GetLength());
            Console.WriteLine("GetHeight：" + tree.GetHeight(tree.headNode));
            Console.WriteLine("IsEmpty：" + tree.IsEmpty());

            //Console.Clear();

            Console.ReadLine();
        }
    }
}
