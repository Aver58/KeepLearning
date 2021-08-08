using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
    class _06_RebuildBinaryTree
    {
        /*
         输入某二叉树的前序遍历和终须遍历的结果，请重建出该二叉树。
         input：{1,2,4,7,3,5,6,8}，{4,7,2,1,5,3,8,6}
         output:
             */

        public class BinaryTreeNode
        {
            public int value;
            public BinaryTreeNode left;
            public BinaryTreeNode right;
            public BinaryTreeNode(int data)
            {
                value = data;
                left = right = null;
            }
        }

        public class RebuildBinaryTree
        {
            public static BinaryTreeNode ConsturctB_Tree(int[] preorder, int[] inorder)
            {
                if (preorder == null || inorder == null || preorder.Length != inorder.Length
                    || preorder.Length <= 0 || inorder.Length <= 0)
                {
                    return null;
                }
                return ConsturctNode(preorder,0,preorder.Length -1, inorder, 0, inorder.Length - 1);
            }

            public static int GetRootPosInInorder(int rootValue, int[] inOrder)
            {
                for (int i = 0; i < inOrder.Length; i++)
                {
                    if (inOrder[i] == rootValue)
                    {
                        return i;
                    }
                }
                throw new Exception("No Find RootValue!");
            }

            public static BinaryTreeNode ConsturctNode
                (int[] preOrder,int preStartPos,int preEndPos, 
                 int[] inOrder, int inStartPos, int inEndPos)
            {
                // 前序遍历的第一个数字是根节点的值
                int rootValue = preOrder[preStartPos];
                BinaryTreeNode root = new BinaryTreeNode(rootValue);

                // 在中序遍历中找到根节点
                int rootPos = GetRootPosInInorder(rootValue,inOrder);

                // 输入序列不匹配
                if (rootPos == inEndPos && inOrder[inEndPos]!= rootValue)
                {
                    return null;
                }

                int leftLength = rootPos - inStartPos;
                int rightLength = inEndPos - rootPos;

                // 如果左边的长度大于0，就构建左子树
                if (leftLength > 0)
                {
                    root.left = ConsturctNode(preOrder,preStartPos + 1,preStartPos+leftLength,
                                              inOrder, inStartPos, rootPos);
                }
                if (rightLength > 0)
                {
                    root.right = ConsturctNode(preOrder, preStartPos + 1 + rootPos, preEndPos,
                                              inOrder,   rootPos,  inEndPos);
                }
                return root;
            }


            //class Program
            //{
            //    static void Main()
            //    {
            //        int[] preorder = { 1, 2, 4, 7, 3, 5, 6, 8 };
            //        int[] inorder = { 4, 7, 2, 1, 5, 3, 8, 6 };

            //        Console.WriteLine(ConsturctB_Tree(preorder, inorder));

            //        Console.ReadLine();
            //    }
            //}
        }
    }
}
