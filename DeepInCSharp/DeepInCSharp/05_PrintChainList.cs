using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Algorithm.ToOffer
{
   
    class TreeNode
    {
        public int m_data;
        public TreeNode m_next;
        public TreeNode(int value) { m_data = value; }
    }
    class _05_PrintChainList
    {
        void AddToTail(TreeNode node,int newValue)
        {
            TreeNode newNode = new TreeNode(newValue);
            if (node == null)
            {
                return;
            }
        }

        void RemoveNode() { }

        /*
            第5题
            输入一个链表的头结点，从尾到头反过来打印出每个结点的值
        */
        void PrintListReverse(TreeNode headNode)
        {
            if (headNode == null)
            {
                return;
            }

            Stack stack = new Stack();
            stack.Push(headNode);

            while (headNode.m_next!=null)
            {
                stack.Push(headNode.m_next);
                headNode = headNode.m_next;
            }

            for (int i = 0; i < stack.Count; i++)
            {
                TreeNode node = (TreeNode)stack.Pop();
                Console.WriteLine(node.m_data);
            }
        }

        void PrintListReverse_Recursive(TreeNode headNode)
        {
            if (headNode == null)
            {
                return;
            }


            while (headNode.m_next != null)
            {
                PrintListReverse_Recursive(headNode.m_next);
                Console.WriteLine(headNode.m_data);
            }
        }
    }
}
