#include "stdafx.h"
#include "TrieCursor.h"

TrieCursor::TrieCursor(DictionaryTrie* trie):
	theTrie(trie),
	currentNode(trie->GetHead())
{
}

void TrieCursor::set(DictionaryTrieNode * newNode)
{
	currentNode = newNode;
}

bool TrieCursor::isWord() const
{
	return currentNode->isWord();
}

bool TrieCursor::getWordUsed() const
{
	return currentNode->GetIsUsed();
}

void TrieCursor::setWordUsed()
{
	currentNode->SetUsed();
}

bool TrieCursor::hasChild(char letter) const
{
	return currentNode->searchLetter(letter) != nullptr;
}

bool TrieCursor::goToChild(char letter)
{
	if(hasChild(letter))
	{
		currentNode = currentNode->searchLetter(letter);
		return true;
	}

	return false;
}

void TrieCursor::goToParent()
{
	currentNode = currentNode->getParent();
}
