#region Copyright © 2020 Aver. All rights reserved.
/*
=====================================================
 AverFrameWork v1.0
 Filename:    TrieTree.cs
 Author:      Zeng Zhiwei
 Time:        2021/3/5 15:32:58
=====================================================
*/
#endregion

using System.Collections.Generic;
/// <summary>
/// 单词查找树方法
/// 经常被搜索引擎系统用于文本词频统计，查询效率比哈希表高
/// </summary>
/*
根节点不包含字符，除根节点外每一个节点都只包含一个字符。
从根节点到某一节点，路径上经过的字符连接起来，为该节点对应的字符串。
每个节点的所有子节点包含的字符都不相同。
     */
public class TrieTree
{
    #region TrieNode

    /// <summary>
    /// 单词查找树节点
    /// </summary>
    internal class TrieNode
    {
        public bool isEnd;
        /// <summary>
        /// 该节点的值
        /// </summary>
        public char value;
        /// <summary>
        /// 该节点的孩子节点
        /// </summary>
        private Dictionary<char, TrieNode> m_children;
        public int WordCount;          //用于记录以该节点结尾的单词出现的次数
        public int PrefixCount;        //用于记录以该节点结尾的前缀出现的次数

        public TrieNode():this(null,false){}

        public TrieNode(char? value, bool isEnd)
        {
            if(value != null)
                this.value = (char)value;

            WordCount = 0;
            PrefixCount = 0;
            this.isEnd = isEnd;
            m_children = new Dictionary<char, TrieNode>(0);
        }

        public void AddChild(char value, TrieNode node)
        {
            m_children.Add(value, node);
        }

        public TrieNode GetChild(char value)
        {
            TrieNode node;
            if(m_children.TryGetValue(value, out node))
                return node;
            return null;
        }
    }

    #endregion

    private TrieNode head = new TrieNode();

    /// <summary>
    /// 插入节点
    /// 插入时，单词查找树不存在该字符，则需要创建一个新的节点来保存该字符，此时词频为 1
    /// 插入时，单词查找树中已经存在此字符，则进入下一步，此时词频+1
    /// </summary>
    public void Insert(string value) 
    {
        if(value.Length <= 0)
            return;
        
        TrieNode node = head;
        for(int i = 0; i < value.Length; i++)
        {
            char c = value[i];
            TrieNode child = node.GetChild(c);
            //该字符并没有在相应的孩子节点中
            if(child == null)
            {
                var isEnd = i == value.Length - 1;
                child = new TrieNode(c, isEnd);
                node.AddChild(c, child);
            }
           
            node.PrefixCount++;
            node = child;
        }
        node.WordCount++;
    }

    /// <summary>
    /// 搜索节点
    /// </summary>
    public bool Search(string value) 
    {
        TrieNode node = head;
        for(int i = 0; i < value.Length; i++)
        {
            char c = value[i];
            TrieNode child = node.GetChild(c);
            if(child == null)
                return false;
            node = child;
        }
        return node.isEnd;
    }

    /// <summary>
    /// 以该字符串开始
    /// </summary>
    public bool StartWith(string value)
    {
        TrieNode node = head;
        for(int i = 0; i < value.Length; i++)
        {
            char c = value[i];
            TrieNode child = node.GetChild(c);
            if(child == null)
                return false;
            node = child;
        }
        return true;
    }

    //给定某个单词，返回其在文本中出现的次数
    public int GetWordFrequency(string value)
    {
        TrieNode node = head;
        for(int i = 0; i < value.Length; i++)
        {
            char c = value[i];
            TrieNode child = node.GetChild(c);
            if(child == null)
                return 0;
            
            node = child;
        }
        return node.WordCount;
    }

    //给定某个前缀，返回其在文本中出现的次数
    public int GetPrefixFrequency(string value)
    {
        TrieNode node = head;
        for(int i = 0; i < value.Length; i++)
        {
            char c = value[i];
            TrieNode child = node.GetChild(c);
            if(child == null)
                return 0;

            node = child;
        }
        return node.PrefixCount;
    }
    //统计文本中出现的所有单词及出现的次数
}