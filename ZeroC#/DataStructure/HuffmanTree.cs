using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructure
{
    #region  哈夫曼树的定义
    /*
        1. 带权路径长度(WPL)：设二叉树有n个叶子结点，每个叶子结点带
        有权值 W(k)，从根结点到每个叶子结点的长度为 L(k)，则每个叶子结
        点的带权路径长度之和就是：
      WPL = 所有 W * L 的和
        2. 最优二叉树或哈夫曼树: WPL最小的二叉树 

        哈夫曼树的特点:
       没有度为1的结点；
       哈夫曼树的任意非叶节点的左右子树交换后仍是哈夫曼树；
       n个叶子结点的哈夫曼树共有2n-1个结点；
       对同一组权值，存在不同构的两棵哈夫曼树呢？
         */

    public class MinHeap:HeapBase
    {

    }
    public class HuffmanTreeNode
    {
        int weight;
        HuffmanTreeNode left,right;
    }
    #endregion
    class HuffmanTree
    {

    }

    #region 哈夫曼编码
    //给定一段字符串，如何对字符进行编码，可以使得该字符串的编码存储空间最少？

    //    【分析】
    //（1）用等长ASCII编码：58 ×8 = 464位；
    //（2）用等长3位编码：58 ×3 = 174位；
    //（3）不等长编码：出现频率高的字符用的编码短些，出现频率低
    //的字符则可以编码长些？

    //    怎么进行不等长编码？
    //如何避免二义性？
//    前缀码prefix code：任何字符的编码都不是另一字符编码的前缀
// 可以无二义地解码
    #endregion
}
